---
title: Maze Generation
asg: Deep Dive 2
permalink: /dd2/
---

On this page:  
✔️ [Pre-Req Info](#pre)  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Pre-Req Info {#pre}
Before jumping into this assignment, below are the topics you're expected to be familiar with. If you need some review, check out our [resource/prep page](/prep).  
✔️ Binary notation ([overview](https://arith-matic.com/notebook/binary-numbers))  
✔️ Command line arguments ([tutorial](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/), [video](https://www.youtube.com/watch?v=h2LGTzQXzJU))  
✔️ Reading and writing to files ([tutorial](https://www.w3schools.com/cpp/cpp_files.asp), [reference page](https://www.cplusplus.com/doc/tutorial/files/))  
✔️ Classes ([OOP material](/prep#oop))  

---

#### Motivation (Why are we doing this?) {#motivation}
The goal of this deep dive is to provide a review of **classes** and `dynamic arrays` (non-negotiable) as well as continuing to get you comfortable with **basic C++ tasks**. Namely, in this assignment you'll be:  
✔️ manipulating data with dynamic arrays (vectors) and matrices  
✔️ using an object oriented design  
✔️ processing command line arguments  
✔️ writing files  

---

#### Background Info {#bgi}
Your goal in this assignment is to develop a command line tool that will generate a random maze, given some options provided by the user. 

##### What is a Maze?
A maze is a puzzle, with starting and ending points, in which a player is tasked to find a path connecting a starting point to an ending point.  While many algorithms for automatically generating random mazes have been proposed, in this assignment we will implement a **randomized depth-first search** approach that uses **dynamic arrays**.  For the context of this assignment, every maze is two-dimensional and it only contains 1 starting and 1 ending cell.  There should be exactly one path connecting both cells.  The example below illustrates a random maze of dimensions `n=6, m=12`, `n` rows and `m` columns.  Note that the starting point always happens at cell `0, 0` and the ending point at `n-1, m-1`.

![Two dimensional maze](/dds/dd2/maze-6-12.png)

##### Generating a Maze
A data structure for representing a maze in memory may be a two dimensional array in which every cell encodes whether each of the 4 walls is closed or open.  We can assume each cell has 4 walls: `north`, `south`, `east`, and `west`.

The algorithm for generating a maze starts with a grid where only 2 walls are removed, `north` for the starting position, and `south` for the ending position, as illustrated in the 6x6 grid below.

![The starting point for a 6x6 maze, with the north wall at (0,0) and south wall at (n-1,m-1) removed](/dds/dd2/start-6-6.png)

A common approach for maze generation involves removing interior walls iteratively.  At each iteration a wall is removed to connect two adjacent cells.  This iterative process must follow these rules:

- Walls to be removed should be selected randomly. 
	- Use `std::rand()` ([read more](http://www.cplusplus.com/reference/cstdlib/rand/)) to generate random numbers and `std::srand()` ([read more](http://www.cplusplus.com/reference/cstdlib/srand/)) to provide a seed to the random number generator
- There should be exactly one path connecting the starting and ending cells
- Every cell must be reachable from the starting cell

The algorithm below should be followed in your implementation.  While this is not the most efficient way to solve the problem of maze generation, for our intents and purposes, it's a good fit. This algorithm can (and should) be implemented with the support of dynamic arrays (`std::vector` in `C++`).  

> We **strongly suggest** you to trace this algorithm on paper using a small example (e.g. a 4 x 4 grid) until you fully understand how it works, before starting to code.

```text
create empty dynamic array (henceforth referred to as A)
mark cell [0,0] as visited
insert cell [0,0] at the end of A
while A is not empty
    remove last element from A (henceforth referred to as current)
    current's neighbors not visited yet (henceforth referred to as neighbors)
    if neighbors is not empty
        insert current at the end of A
        pick a random neighbor from neighbors (henceforth referred to as neigh)
        remove the wall between current and neigh
        mark neigh as visited
        insert neigh at the end of A
    endif
endwhile
```

Picking a random neighbor **must** follow this procedure: 
1. Check the neighbors of a cell in N-S-E-W order and...
2. ...**append** the neighbors that were not visited yet into an empty vector `neighbors`
3. Then use the index `idx`, as defined below, to pick a random neighbor with `neighbors[idx]`

```c++
idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
```

> **Notes:** 
- The `u` following the `1` in the `1u` in the code above signifies that the 1 is `unsigned`. In C++, numbers are `signed` by default (meaning they can be either positive or negative) so by declaring it `unsigned`, we're saying it cannot be negative ([read more](https://stackoverflow.com/questions/621290/what-is-the-difference-between-signed-and-unsigned-variables)).
- `RAND_MAX` is a predefined macro ([read more](http://www.cplusplus.com/reference/cstdlib/RAND_MAX/)).

---

#### Your Task {#task}
Your goal in this assignment is to develop a command line tool that will generate a random maze, given some options (described below) provided by the user.

**The options for the user** will be provided via the following **command line arguments**:
```text
<seed>  the seed value for the random number generator
<N>     number of rows in the grid N > 0
<M>     number of cols in the grid M > 0
<fname> file name for the output
```

> The `seed` argument is very important as it initializes the random number generator.  If you change the seed, you will generate a different maze.  In your code make sure you call this function **exactly once** before generating the maze:

```c++
std::srand(seed);
```

The last argument will be used to save the generated maze into a text file.  Note that you can provide any value as `fname`.  See the example below:

```bash
$ ./generator 0 10 10 example.txt
```

---

**The files that you will generate** will be in the format described below.

> The description below assumes you have a basic understanding of binary notation, if you don't or if you need a refresher, please check out this [introduction to binary notation](https://arith-matic.com/notebook/binary-numbers).

The file format for saving the maze is a two dimensional array of integers, where each integer is used to represent a cell and its walls.  Each integer in the matrix ranges from 0 to 15.  The idea behind this representation is that the walls are encoded using 4 bits (a nibble), and the integers are their corresponding values in decimal notation.  The figure below illustrates the encoding, with 4 of the possible 16 possibilities. To see the 4-bit representation of all possible numbers (0-15), see [this table](https://www.swarthmore.edu/NatSci/echeeve1/Ref/BinaryMath/NumSys.html#hex).

![Two-dimensional maze](/dds/dd2/walls.jpg)

When saving the grid, the output file must be a `text file` in which cell values are separated by a single whitespace, and organized in `n` rows and `m` columns (the grid dimensions).  For example, the image below shows one grid with 5 rows and 5 columns.  The text file representation of the grid appears on the left, and the corresponding maze appears on the right.  Note how each number maps into a cell encoding its walls. Note that every integer value is separated by a **single** whitespace.

![Two-dimensional maze](/dds/dd2/example.png)

> If you want to visualize a maze, you can convert the raw text file into a PDF.  This will be useful to visualize what your program is doing.  We prepared a script that can help you do this, for more details please refer to [this repl.it](https://repl.it/@VictoriaChvez/maze-converter).

---

#### Requirements {#reqs}
Your submission will be **tested and graded by an autograder**, for this reason it cannot be stressed enough that your program must **exactly** follow the assignment specifications:  

1. Design a class for the grid, using a header file for your class declaration (see below)
2. You should receive **no warning or error messages** upon compilation with the **exact following command**
```bash
	$ g++ -std=c++11 -Wall main.cpp maze.cpp -o generator
```
3. Your command line program should use the following arguments (CLAs), in this exact order:
```text
	<seed>  the seed value for the random number generator
	<N>     number of rows in the grid N > 0
	<M>     number of cols in the grid M > 0
	<fname> file name for the output
```
4. Use the seed value correctly, as described in the section above.
5. Generate maze correctly, per the algorithm described in the section above.

**BEFORE HANDING IN:** Test that your program works by compiling your program with the command in Requirement #2. Successful execution of this command should create an exectuable file named `generator`, which you should be able to execute using the arguments as outlined in Requirement #4 (example usecase below).
```bash
$ ./generator 0 10 10 example.txt
```

---

#### Handing in {#submit}
You should have **three files**:
- `maze.h`: class declaration
- `maze.cpp`: implementation of all methods defined in `maze.h`
- `main.cpp`: driver program that takes CLAs and uses the class `Maze` to generate output

To submit your solution to Gradescope, select the three required files and use the **drag and drop** option.

---

#### Grade Breakdown {#grading}
This assignment covers the **non-negotiable topic of** `dynamic arrays` as well as the topics of **classes** and **basic C++ tasks** and your level of knowledge on them will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 3**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 4**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 5**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by [Dr. Marco Alvarez](https://homepage.cs.uri.edu/~malvarez/), used and modified with permission.
