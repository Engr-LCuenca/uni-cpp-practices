#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct RouteGraph {
    vector<string> cities;
    vector<vector<int>> adjacency;

    RouteGraph() : cities({"Lima", "Cusco", "Arequipa", "Trujillo", "Piura"}) {
        adjacency = {
            {0, 400, 0, 250, 300},
            {400, 0, 350, 0, 0},
            {0, 350, 0, 180, 0},
            {250, 0, 180, 0, 220},
            {300, 0, 0, 220, 0}
        };
    }
};

void printCities(const RouteGraph& graph) {
    cout << "Available cities:\n";
    for (size_t i = 0; i < graph.cities.size(); ++i) {
        cout << i << ". " << graph.cities[i] << "\n";
    }
}

bool hasDirectFlight(const RouteGraph& graph, int from, int to) {
    if (from < 0 || from >= static_cast<int>(graph.cities.size()) ||
        to < 0 || to >= static_cast<int>(graph.cities.size())) {
        return false;
    }
    return graph.adjacency[from][to] > 0;
}

int calculateRouteCost(const RouteGraph& graph, int from, int to) {
    if (from == to) return 0;
    if (!hasDirectFlight(graph, from, to)) {
        for (int mid = 0; mid < static_cast<int>(graph.cities.size()); ++mid) {
            if (mid == from || mid == to) continue;
            if (hasDirectFlight(graph, from, mid) && hasDirectFlight(graph, mid, to)) {
                return graph.adjacency[from][mid] + graph.adjacency[mid][to];
            }
        }
    }
    return graph.adjacency[from][to];
}

int countOutgoingConnections(const RouteGraph& graph, int cityIndex) {
    int count = 0;
    for (int value : graph.adjacency[cityIndex]) {
        if (value > 0) ++count;
    }
    return count;
}

int findMostConnectedCity(const RouteGraph& graph) {
    int bestIndex = 0;
    int bestConnections = -1;
    for (size_t i = 0; i < graph.cities.size(); ++i) {
        int connections = countOutgoingConnections(graph, static_cast<int>(i));
        if (connections > bestConnections) {
            bestConnections = connections;
            bestIndex = static_cast<int>(i);
        }
    }
    return bestIndex;
}

int main() {
    RouteGraph graph;

    cout << "========================================\n";
    cout << "Air Routes and Connections Simulator\n";
    cout << "========================================\n";
    printCities(graph);

    while (true) {
        int option = 0;
        cout << "\nChoose an option:\n";
        cout << "1. Check direct flight\n";
        cout << "2. Calculate route cost with one stop\n";
        cout << "3. Show most connected city\n";
        cout << "4. Exit\n";
        cout << "Option: ";
        cin >> option;

        if (option == 4) {
            cout << "Goodbye!\n";
            break;
        }

        if (option < 1 || option > 3) {
            cout << "Invalid option. Please try again.\n";
            continue;
        }

        int from = -1, to = -1;
        cout << "Enter origin city index: ";
        cin >> from;
        cout << "Enter destination city index: ";
        cin >> to;

        if (from < 0 || from >= static_cast<int>(graph.cities.size()) ||
            to < 0 || to >= static_cast<int>(graph.cities.size())) {
            cout << "Invalid city index.\n";
            continue;
        }

        if (option == 1) {
            cout << (hasDirectFlight(graph, from, to) ? "Direct flight exists." : "No direct flight.") << "\n";
        } else if (option == 2) {
            int cost = calculateRouteCost(graph, from, to);
            if (cost > 0) {
                cout << "Route cost: " << cost << "\n";
            } else {
                cout << "There is no available route with that connection pattern.\n";
            }
        } else {
            int city = findMostConnectedCity(graph);
            cout << "Most connected city: " << graph.cities[city] << " (" << countOutgoingConnections(graph, city) << " outgoing connections)\n";
        }
    }

    return 0;
}
