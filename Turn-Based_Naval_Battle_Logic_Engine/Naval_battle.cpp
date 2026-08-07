#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;

static const int ROWS = 8;
static const int COLS = 8;

struct Ship {
    vector<pair<int,int>> cells;
    int hits = 0;
    bool contains(int r, int c) const {
        for (auto &p : cells) if (p.first == r && p.second == c) return true;
        return false;
    }
    bool isSunk() const { return hits >= static_cast<int>(cells.size()); }
};

void printPlayerGrid(const vector<vector<char>>& grid) {
    cout << "  ";
    for (int c = 0; c < COLS; ++c) cout << (c+1) << ' ';
    cout << '\n';
    for (int r = 0; r < ROWS; ++r) {
        cout << (r+1) << ' ';
        for (int c = 0; c < COLS; ++c) cout << grid[r][c] << ' ';
        cout << '\n';
    }
}

bool placeShipRandom(Ship &ship, vector<vector<char>>& hidden, mt19937 &rng, int length) {
    uniform_int_distribution<int> dirDist(0,1); // 0 horizontal, 1 vertical
    uniform_int_distribution<int> rowDist(0, ROWS-1);
    uniform_int_distribution<int> colDist(0, COLS-1);

    for (int attempt = 0; attempt < 200; ++attempt) {
        int dir = dirDist(rng);
        int r = rowDist(rng);
        int c = colDist(rng);

        int dr = dir == 1 ? 1 : 0;
        int dc = dir == 0 ? 1 : 0;

        int endR = r + dr * (length - 1);
        int endC = c + dc * (length - 1);
        if (endR < 0 || endR >= ROWS || endC < 0 || endC >= COLS) continue;

        bool ok = true;
        vector<pair<int,int>> cells;
        for (int i = 0; i < length; ++i) {
            int rr = r + i * dr;
            int cc = c + i * dc;
            if (hidden[rr][cc] != '.') { ok = false; break; }
            cells.emplace_back(rr, cc);
        }
        if (!ok) continue;

        // Place
        ship.cells = move(cells);
        for (auto &p : ship.cells) hidden[p.first][p.second] = 'S';
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    bool reveal = false;
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--reveal") reveal = true;
        else if (arg == "--seed" && i + 1 < argc) { seed = static_cast<unsigned int>(stoul(argv[++i])); }
        else if (arg.rfind("--seed=", 0) == 0) { seed = static_cast<unsigned int>(stoul(arg.substr(7))); }
    }

    vector<vector<char>> hidden(ROWS, vector<char>(COLS, '.'));
    vector<vector<char>> player(ROWS, vector<char>(COLS, '.'));

    // Ship sizes: mix of small and medium ships
    vector<int> shipSizes = {4, 3, 2, 2};
    vector<Ship> ships;

    // RNG (seedable for reproducible demos)
    mt19937 rng(seed);

    if (reveal) {
        cout << "[Debug] Using seed: " << seed << "\n";
    }

    for (int size : shipSizes) {
        Ship s;
        if (!placeShipRandom(s, hidden, rng, size)) {
            cerr << "Failed to place all ships. Exiting.\n";
            return 1;
        }
        ships.push_back(move(s));
    }

    if (reveal) {
        cout << "\nHidden ship map (S=ship):\n";
        cout << "  ";
        for (int c = 0; c < COLS; ++c) cout << (c+1) << ' ';
        cout << '\n';
        for (int r = 0; r < ROWS; ++r) {
            cout << (r+1) << ' ';
            for (int c = 0; c < COLS; ++c) cout << hidden[r][c] << ' ';
            cout << '\n';
        }
    }

    int shotsAllowed = 30;
    int shotsTaken = 0;

    cout << "Turn-Based Naval Battle (8x8)\n";
    cout << "Enter row and column as numbers 1..8 separated by space. Enter 0 0 to quit.\n";

    while (shotsTaken < shotsAllowed) {
        cout << "\nPlayer grid:\n";
        printPlayerGrid(player);
        cout << "Shots remaining: " << (shotsAllowed - shotsTaken) << '\n';

        int r, c;
        cout << "Enter row and column: ";
        if (!(cin >> r >> c)) {
            cout << "Invalid input. Exiting.\n";
            return 1;
        }
        if (r == 0 && c == 0) { cout << "Player quit.\n"; break; }
        if (r < 1 || r > ROWS || c < 1 || c > COLS) { cout << "Coordinates out of range. Try 1..8.\n"; continue; }

        --r; --c;
        if (player[r][c] != '.') { cout << "You already shot there. Try a different cell.\n"; continue; }

        ++shotsTaken;

        if (hidden[r][c] == 'S') {
            player[r][c] = 'X';
            // find which ship
            for (auto &s : ships) {
                if (s.contains(r,c)) { s.hits++; break; }
            }
            cout << "Hit!\n";
        } else {
            player[r][c] = 'O';
            cout << "Miss.\n";
        }

        bool allSunk = true;
        for (auto &s : ships) {
            if (!s.isSunk()) { allSunk = false; break; }
        }

        if (allSunk) {
            cout << "\nCongratulations — you sank all ships!\n";
            break;
        }
    }

    // Final scoring
    int sunk = 0;
    int totalCells = 0;
    for (auto &s : ships) { if (s.isSunk()) ++sunk; totalCells += static_cast<int>(s.cells.size()); }

    int hits = 0;
    for (int r = 0; r < ROWS; ++r) for (int c = 0; c < COLS; ++c) if (player[r][c] == 'X') ++hits;

    int score = hits * 10 + sunk * 50 - max(0, shotsTaken - hits);

    cout << "\nGame over. Ships sunk: " << sunk << " / " << ships.size() << '\n';
    cout << "Shots taken: " << shotsTaken << "  Hits: " << hits << "\n";
    cout << "Score: " << score << "\n";
    cout << "Final player grid:\n";
    printPlayerGrid(player);

    return 0;
}
