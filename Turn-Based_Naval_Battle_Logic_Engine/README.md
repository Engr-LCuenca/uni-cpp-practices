# Turn-Based Naval Battle Logic Engine

Simple console-based turn-driven naval battle (Battleship-like) logic engine implemented in C++. The project demonstrates dynamic matrices, randomized ship placement without overlap, shot handling, and scoring.

Features

- 8x8 ocean grid represented by dynamic 2D vectors
- Randomized placement of ships of varying sizes (no overlap)
- Player-facing grid that records hits (`X`) and misses (`O`)
- Limited number of shots; game ends when all ships are sunk or shots run out

Build

```bash
g++ Naval_battle.cpp -o Naval_battle
```

Run

```bash
./Naval_battle [--seed N] [--reveal]
```

Examples

- Run normally (random placements):

```bash
./Naval_battle
```

- Run with a fixed seed (reproducible demo):

```bash
./Naval_battle --seed 42
```

- Run and reveal ship positions (debug/demo):

```bash
./Naval_battle --reveal --seed 42
```

Usage

- Enter row and column numbers between `1` and `8` separated by space to fire.
- Enter `0 0` to quit early.

Design notes

- Ships are represented internally on a hidden grid and are not displayed to the player unless `--reveal` is used.
- Ship placement chooses random orientation and location and retries until a valid placement is found.

Ideas for extension

- Add AI opponent and two-player mode
- Show a small map legend and replay
- Implement file-based level presets and fixed coordinates
