# Random Distribution of Calls Among Service Modules

A simple C++ console application that simulates the random distribution of calls among four service modules and analyzes whether the distribution is balanced.

## Overview

This project generates a random sequence of calls and assigns each one to one of four modules. It then calculates:

- the expected frequency for each module
- an acceptable range of variation
- the percentage of calls received by each module
- the most and least used modules
- whether the distribution is balanced

## Features

- Input validation for the number of calls
- Random generation of calls
- Frequency counting for each module
- Statistical analysis of the distribution
- Clear console output for reporting

## How to Run

Compile the program with:

```bash
g++ Random_distribution.cpp -o Random_distribution
```

Run it with:

```bash
./Random_distribution
```

## Example Flow

The program asks the user to enter a value for N, where:

- N must be between 100 and 400
- N must be a multiple of 4

Then it displays a summary report based on the generated distribution.

## Purpose

This project is intended as a daily C++ practice exercise focused on:

- loops
- arrays
- random number generation
- basic statistics
- console-based program design

## Technologies

- C++
- Standard Library
