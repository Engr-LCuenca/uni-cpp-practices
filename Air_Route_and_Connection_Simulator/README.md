# Air Routes and Connections Simulator

A polished C++ console application that models a small air transport network using an adjacency matrix.

## Overview

This project uses a $5 \times 5$ integer matrix to represent direct flights between five cities. A value greater than zero at position `[i][j]` means there is a direct connection from city `i` to city `j`, and the value represents the ticket cost. A value of `0` means no direct flight exists.

## Features

- Check whether a direct flight exists between two cities.
- Calculate the total cost of a route with one stop (for example, from A to C via B).
- Identify the city with the highest number of outgoing connections.
- Offer a simple interactive console menu.

## Build

```bash
g++ Air_Routes_and_Connections.cpp -o Air_Routes_and_Connections
```

## Run

```bash
./Air_Routes_and_Connections
```

## Example

If the user checks the route from Lima to Cusco, the program can detect a direct connection with a cost of 400. If the user asks for a route from Lima to Arequipa through Cusco, the program can calculate the route cost as 400 + 350.

## Why this project is useful

This project demonstrates:

- adjacency matrices in graph theory.
- simple graph traversal concepts.
- control flow with menus and validation.
- clean C++ structures for practical modeling.
