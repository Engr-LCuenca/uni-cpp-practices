#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Antena {
    int id;
    float x;
    float y;
    float range;
};

struct Usuario {
    float x;
    float y;
};

// Compute Euclidean distance between antenna and user
static float distance(const Antena* a, const Usuario* u) {
    float dx = a->x - u->x;
    float dy = a->y - u->y;
    return sqrtf(dx*dx + dy*dy);
}

// Using pointers: finds the index of the closest antenna and whether the user is within its range.
// Returns pointer to the closest Antena (or nullptr if count==0).
const Antena* findClosestAntenna(const Antena* antennas, size_t count, const Usuario* user, size_t* outIndex, bool* outInRange) {
    if (count == 0) return nullptr;
    const Antena* best = nullptr;
    float bestDist = numeric_limits<float>::infinity();
    size_t bestIdx = 0;

    for (size_t i = 0; i < count; ++i) {
        const Antena* a = &antennas[i];
        float d = distance(a, user);
        if (d < bestDist) {
            bestDist = d;
            best = a;
            bestIdx = i;
        }
    }

    if (outIndex) *outIndex = bestIdx;
    if (outInRange) *outInRange = (bestDist <= best->range);
    return best;
}

int main() {
    // Sample antenna array
    vector<Antena> antennas = {
        {101, 0.0f, 0.0f, 15.0f},
        {102, 20.0f, 5.0f, 10.0f},
        {103, -10.0f, -5.0f, 8.0f},
        {104, 5.0f, 18.0f, 12.0f}
    };

    // Demo user position (change as needed)
    Usuario user{7.0f, 3.0f};

    size_t idx = 0;
    bool inRange = false;
    const Antena* closest = findClosestAntenna(antennas.data(), antennas.size(), &user, &idx, &inRange);

    if (closest) {
        cout << "User position: (" << user.x << ", " << user.y << ")\n";
        cout << "Closest antenna ID: " << closest->id << " (index " << idx << ")\n";
        cout << "Antenna position: (" << closest->x << ", " << closest->y << ") range=" << closest->range << "\n";
        float d = distance(closest, &user);
        cout << "Distance to antenna: " << d << "\n";
        cout << "Within coverage: " << (inRange ? "YES" : "NO") << "\n";
    } else {
        cout << "No antennas available.\n";
    }

    return 0;
}
