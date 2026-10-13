## Zombie Outbreak Data Structure

This project provides a set of data structures implemented in C to simulate and analyze scenarios involving a zombie outbreak. It includes efficient algorithms and data organization techniques to model populations, track infection spread, and manage resources. The code is designed for educational purposes, demonstrating how data structures can be applied to real-world problems such as epidemic simulations.

The repository implements a simulation of a zombie outbreak using data structures in C. The core logic models a city as an N x N grid, where each cell can be infected or safe. The infection spreads to adjacent cells (up, down, left, right) in discrete time steps.

Key features:

Uses a queue data structure to efficiently track cells to be processed as the infection spreads (Breadth-First Search).
The user inputs the size of the grid and the initial infection states.
The program calculates the minimum time required to infect all reachable areas of the city.
If some areas cannot be infected, it reports failure.
The code demonstrates practical usage of queues and BFS for epidemic modeling in C.

## Author
MD SIRAJUL ISLAM
