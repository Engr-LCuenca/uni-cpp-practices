# Incident Management in an IT Support Center

A simple C++ console application that simulates incident registration and reporting for an IT support environment.

## 🚀 Overview

This project collects incident data such as:

- the shift of the incident (Morning or Afternoon)
- the severity level from 1 to 5

Once the data is entered, the program generates a summary report including:

- total incidents
- critical incidents
- overall average severity
- average severity by shift
- critical incidents by shift
- the shift with the highest average severity

## ✨ Features

- Input validation for the number of incidents
- Input validation for shift selection
- Input validation for severity levels
- Summary statistics for the complete dataset
- Per-shift analysis
- Clear console-based reporting

## ▶️ How to Run

Compile the program with:

```bash
g++ incident_management.cpp -o incident_management
```

Run it with:

```bash
./incident_management
```

## 🧪 Example Flow

The program will prompt you to enter:

1. the number of incidents
2. the shift for each incident
3. the severity of each incident

After that, it will display a structured report with the computed metrics.

## 📌 Purpose

This project is intended as a C++ practice exercise focused on:

- loops
- conditionals
- input validation
- simple statistics
- console-based user interaction

## 🛠️ Technologies

- C++
- Standard Library
