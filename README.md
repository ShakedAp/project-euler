# project-euler

This repository contains a collection of possible solutions for problems from [Project Euler](https://projecteuler.net/), implemented in C. Project Euler is a series of challenging mathematical/computer programming problems that require creative solutions. The problems are designed to be solved using algorithms and mathematical concepts. 

## Repository Structure

The repository is organized into directories, with each directory representing a specific problem from Project Euler. Inside each directory, you will find the following files:
* README.md: Provides the problem statement and additional information about the problem
* q\<num\>.c: Contains a possible solution to the problem, implemented in c.
* Makefile: Contains the code to build the solution binary.

Also, a test program is included to test the solution of each problem implemented:
* Makefile: Contains the code to build the test program and all of the individual problem solutions.
* test.c: Contains the code for the test program.

## How to Use
To view the solutions:
1. Clone the repository to your local machine: `git clone https://github.com/ShakedAp/project-euler.git`
2. Navigate to the desired problem's directory: `cd q<num>`
3. Read *README.md* to view the problem, and *q\<num\>.c* for the solution



In order to use the test program:
1. Compile the test program with `make test`
2. Run `./test <problem-number>` eg:(`./test 3`, for problem 3)
3. Input the result for the problem

Easier use of the test program is with piping:
* Run `./solution-bin | ./test <problem-number`
* Example: `./q4/q4 | ./test 4`

 

## Disclaimer
The solutions provided in this repository are meant to be educational and demonstrate different programming techniques. They may not be the most optimal or efficient solutions. It is recommended to attempt solving the problems on your own before exploring the solutions here. Enjoy :).