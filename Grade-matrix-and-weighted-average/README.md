# Grade Matrix and Weighted Average

A simple C++ practice project that generates grades for 30 students, computes their weighted averages, and summarizes the results.

## Overview

This program simulates a grade evaluation system where each student has three scores:

- PC
- EP
- EF

The final average is calculated using the following weights:

- PC: 20%
- EP: 30%
- EF: 50%

## Features

- Generates random grades for 30 students
- Calculates the weighted average for each student
- Determines whether each student passes or fails
- Shows the overall average
- Identifies the student with the highest and lowest average

## How to Run

Compile the program with:

```bash
g++ Grade_matrix.cpp -o Grade_matrix
```

Run it with:

```bash
./Grade_matrix
```

## Example Output

```text
Student   PC   EP   EF   Average   Condition
1         10   8    15   11.20     PASSED
...
```

## Project Purpose

This project is intended as a daily C++ practice exercise to improve logic, control flow, and basic matrix handling.

## Technologies

- C++
- Standard Library (iostream, ctime and cstdlib)
