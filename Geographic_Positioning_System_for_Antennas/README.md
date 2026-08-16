# Geographic Positioning System for Antennas

A compact C++ backend demo that models antennas and users on a 2D plane and determines which antenna is the closest and whether the user lies within its coverage radius.

Overview

- `Antena`: struct with `id`, coordinates `(x,y)` as `float`, and `range` (coverage radius).
- `Usuario`: struct with coordinates `(x,y)` as `float`.
- Uses Euclidean distance: $\sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}$ to compute proximity.
- Demonstrates pointer-style APIs: a function receives pointers to the antenna array and user and returns the closest antenna and coverage boolean.

Why this is useful

- Simple simulation to evaluate signal coverage and perform nearest-neighbor queries.
- Basis for more advanced features: weighted signal strength, multi-antenna aggregation, or spatial indexing.

Build

```bash
g++ Geographic_Positioning_System.cpp -o gps_antennas
```

Run

```bash
./gps_antennas
```

Example output

```
User position: (7, 3)
Closest antenna ID: 101 (index 0)
Antenna position: (0, 0) range=15
Distance to antenna: 7.61577
Within coverage: YES
```

How the pointer function works (summary)

- `findClosestAntenna(const Antena* antennas, size_t count, const Usuario* user, size_t* outIndex, bool* outInRange)` iterates the array using pointer indexing, computes distances via a helper `distance()` that accepts pointers, and writes the results into caller-provided output pointers.

Extensions

- Accept user input for coordinates and a list of antennas from a file (CSV). 
- Return the full sorted list of antennas by distance.
- Use k-d tree or spatial hashing for large antenna arrays.
