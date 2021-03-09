---
title: Backtracking
asg: Lab 7
permalink: /lab07/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
The goal of this deep dive is to provide a **experience with recursive backtracking**.

---

#### Background Info {#bgi}

Recursion is the practice of breaking a complicated problem down into small, trivially solvable pieces, and then merging those pieces together to solve the full problem completely. Recursive backtracking however, takes this process to the next level. This method will allow us to discard incorrect pieces & attempt to re-solve that part of the problem with different parameters.

##### A Lesson on Backtracking

Backtracking is a systemic method to iterate over all possible configurations of a search space. The general idea is:

```
0.) Is the task complete? Return true if so.
1.) At any given step, enumerate all possible actions.
	1.2.) Make one of the enumerated actions
	1.3.) Evaluate the new partial solution. If we obtain 'True', also return 'True' else try a different action
2.) If we run out of moves, return 'False' to backback to a previous stage of the problem
```

This strategy can be applied to many problems, and as such represents a 

Let's take a look at an example; solving a game of Sujiko! 

The purpose of this game is to place the numbers 1-9 on the board such that the sum of the four numbers around a circle equal the number in a circle. How would you solve this puzzle?

<p align="center">
  <img src="/labs/images/sujiko/sujiko.png" />
</p>


Lets take a look at an algorithm:

```
0.) Is the win condition met? If so, return true. Otherwise, continue on.
1.) At any given step, record all of the missing values.
	1.2) Place the first missing value into the first open spot on the board.
	1.3) Recursively call this function with the new board. If we obtain True, also return True. 
	     Otherwise, replace the number with the next missing value.
2.) If we tried all of the missing values & none worked, return False so the previous version of this board can try another number.
```

Lets try applying this algorithm to our board:

| First Pass                                   | Second Pass                                   | Seventh Pass                                   |
| -------------------------------------------- | --------------------------------------------- | ---------------------------------------------- |
| ![image](/labs/images/sujiko/first_pass.png) | ![image](/labs/images/sujiko/second_pass.png) | ![image](/labs/images/sujiko/seventh_pass.png) |

We've hit our first dead end, & there are no more missing values to place. This solution is not correct, so we backtrack to the previous version of the board, and change the number that was placed.

| Sixth Pass Revisited                                   | Sixth Pass Modified                                   | Seventh Pass Revisited                             |
| ------------------------------------------------------ | ----------------------------------------------------- | -------------------------------------------------- |
| ![image](/labs/images/sujiko/sixth_pass_revisited.png) | ![image](/labs/images/sujiko/sixth_pass_modified.png) | ![image](/labs/images/sujiko/new_seventh_pass.png) |

This yields another dead end, so we would backtrack back to the 5th empty spot, and change the value there.

| Fifth Pass Revisited                                   | New Fifth Pass                                   | New Sixth Pass                                   |
| ------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------ |
| ![image](/labs/images/sujiko/fifth_pass_revisited.png) | ![image](/labs/images/sujiko/new_fifth_pass.png) | ![image](/labs/images/sujiko/new_sixth_pass.png) |

This process would repeat until we have a solution board:

<p align="center">
  <img src="/labs/images/sujiko/sujiko_solved.png" />
</p>



---

#### Your Task {#task}

Review each of the following problems and fulfil the requirements for this lab

##### <center>N-Queens Problem</center>

The N-Queens problem is the task of placing eight chess queens on an NxN chessboard such that no two queens can attack each other. Let's take a look at this empty 8x8 chess board:

<p align="center">
  <img src="/labs/images/chessboard.png" />
</p>


How would you solve the problem? Let's take a look at pseudocode for the strategy you would probably use.

```
1) Start in the leftmost column
2) If all queens are placed
    return true
3) Try all rows in the current column. 
   Do following for every tried row.
    a) If the queen can be placed safely in this row 
       then mark this [row, column] as part of the 
       solution and recursively check if placing
       queen here leads to a solution.
    b) If placing the queen in [row, column] leads to
       a solution then return true.
    c) If placing queen doesn't lead to a solution then
       unmark this [row, column] (Backtrack) and go to 
       step (a) to try other rows.
3) If all rows have been tried and nothing worked,
   return false to trigger backtracking.
```

> During lab we went over a step-by-step visualization for this problem. If you missed it (or need a refresher) you can view a simulation here: https://www.cs.usfca.edu/~galles/visualization/RecQueens.html

The following is the result of the recursive call tree for solving a 4x4 puzzle.

<p align="center">
  <img src="/labs/images/n-queens-4x4-solved.png" />
</p>

The code to solve the N-Queens problem is given in this lab. Download the code & work to understand how the backtracking is working to solve the problem. After you can follow the code, move on to the next section.

##### <center>Sudoku!</center>

If you are yet unaware of what a Sudoku puzzle is, you are given a partially filled 9x9 board with the objective of filling each cell such that each row, column, and 3x3 subgrid contains all of the digits 1-9. You can **not** change the given values. As an example, here is a puzzle:
	

|              Sudoku Puzzle               |              Sudoku Puzzle Solved               |
| :--------------------------------------: | :---------------------------------------------: |
| ![image](/labs/images/sudoku_puzzle.png) | ![image](/labs/images/sudoku_puzzle_solved.png) |

Now that you know the rules, finish the given code for solving a Sudoku puzzle.

Your strategy will be *very* similar to the solution for N-Queens:

```
1) If we have filled the entire board,  return true
2) For each digit 1-9:
	- If this digit can be placed in this cell
		- Place the digit
        - Recurse to the next empty cell.
        - If that recursive call returns true
            - Return true
        - else
            - Try the next digit
3) If none of the digits yielded a valid solution, backtrack.
```

Before starting the code for this problem, work through a few rounds on paper to ensure you have the correct methodology.

##### <center>Re-N-Queens: A different perspective{#nqueens2}</center>

In the given solution for N-Queens, the puzzle is solved by changing the row a Queen is placed on in a given column.

Write a function that instead solves the puzzle by changing the column a Queen is placed on in a given row.

In other words, instead of solving the puzzle left to right, solve it top to bottom.


---

#### Requirements {#reqs}  
1. Comment the ```solve_rec()``` function in the solution to the N-Queens problem to show you fully understand the solution.
2. Copy the ```solve_rec()``` function and modify it such that it solves the N-Queens problem as described in [Re-N-Queens: A different perspective](#nqueens2).
3. Finish the Sudoku program using recursive backtracking.
---

#### Handing in {#submit}
Please call a TA over to get checked off before leaving your lab section (regardless of how far you got). If you want to continue working on your lab after your lab section, come to [hours](/staff#sched) to get checked off.

---

#### Grade Breakdown {#grading}
This assignment covers the **topic/nonnegot XXX** and your level of knowledge on them will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirement](#reqs) **1**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 and 2**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 3**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by [Dr. Marco Alvarez](https://homepage.cs.uri.edu/~malvarez/), used and modified with permission.
