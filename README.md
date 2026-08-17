# uni-cpp-practices

Collection of small, polished C++ practice projects suitable for learning and portfolio use. Each project lives in its own folder with a `README.md` that documents usage and examples.

Projects

- Geographic_Positioning_System_for_Antennas/ — antenna coverage demo
- Turn-Based_Naval_Battle_Logic_Engine/ — small Battleship-like engine
- Shift*cipher*(Caesar cipher)/ — Caesar cipher encrypt/decrypt demo

Quick start

```bash
g++ -std=c++11 Geographic_Positioning_System_for_Antennas/Geographic_Positioning_System.cpp -o gps_antennas
./gps_antennas
```

CI

This repo includes a simple GitHub Actions workflow that compiles all `*.cpp` files to ensure they build on push and pull requests.

License:

MIT

# UNI Academic C++ Practices

## Description

This repository centralizes a curated collection of 5 algorithmic challenges and academic practices implemented in C++ from the Universidad Nacional de Ingeniería (UNI). It showcases foundational software engineering concepts, data structures, and mathematical problem-solving applied to real-world logic simulators.

## Projects Directory

1. _Basic Bank Account Simulator (/Basic_bank_account_simulator)_
   - Description: Simulates core banking operations such as deposits, withdrawals, and balance management using basic object-oriented or procedural C++ structures.

2. _Grade Matrix and Weighted Average (/Grade_matrix-and-weighted-average)_
   - Description: Generates and processes multi-dimensional arrays tracking student metrics, extracting highest grades, individual/global averages, and academic approval ratios.

3. _Incident Management in an IT Support Center (/Incident_management_in_an_IT_support_center)_
   - Description: Models a systemic ticket and log tracking structure for incident management, handling data structures to organize and update technical support requests.

4. _Random Distribution of Calls Among Service Managers (/Random_distribution_of_calls_among_servic_managers)_
   - Description: Implements randomized distribution algorithms and statistical modeling to load-balance inbound calls across available service nodes or managers.

5. _Supermarket Expense Tracker (/Supermarket-expense-tracker)_
   - Description: Tracks user purchases and budgetary allocations, computing itemized costs, totals, and financial data aggregation.

## Development Workflow & Core Philosophy

Every solution in this repository reflects a strict human-AI collaborative pipeline:

- _Academic Core:_ The foundational logic, algorithmic constraints, and mathematical models were originally designed and solved by me by hand during rigorous university assessments.
- _AI Optimization:_ Leveraged advanced language models to translate manual solutions into production-ready C++ code, optimizing syntax, memory safety, and readability.
- _QA & Supervision:_ Personally audited, compiled, and tested every implementation to guarantee logical precision, structural integrity, and zero runtime errors.

## License

MIT
