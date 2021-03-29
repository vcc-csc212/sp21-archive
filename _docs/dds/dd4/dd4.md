---
title: Tic Tac Toe w/ AI
asg: Deep Dive 4
permalink: /dd4/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Pre-Req Info](#pre)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

---

#### Motivation (Why are we doing this?) {#motivation}
The goal of this deep dive is to provide you an opportunity to create a one and two player Tic Tac Toe game that's executable through the command line. You'll be practicing **basic C++ tasks** and **recursive backtracking**. Namely, in this assignment you'll be:  
✔️ implementing code using pointers and dynamic memory allocation  
✔️ implementing solutions that involve recursive functions  
✔️ implementing a simple AI utilizing recursive backtracking (simple as in "not the smartest AI")  

---

#### Pre-Req Info {#pre}
Before jumping into this assignment, below are the topics you're expected to be familiar with. If you need some review, check out our [resource/prep page](/prep).  
✔️ Classes ([OOP material](/prep#oop))  
✔️ [Structs](http://www.cplusplus.com/doc/tutorial/structures/)  
✔️ [Macros](https://www.cplusplus.com/doc/tutorial/preprocessor/)

---

#### Background Info {#bgi}

##### Tic Tac Toe
Tic tac toe (ttt), also known as 'noughts and crosses' or 'Xs and Os' is a 2 player game that involves trying to get three marks in a horizontal, vertical, or diagonal row. In ttt, players alternate turns marking a 3x3 grid with either an X (for player 1) or an O (for player 2). The first to get 3 in a row wins and if no one gets three in a row and the grid gets filled up, then the game is over with a tie.

![tic tac toe game](/dds/dd4/ttt-wiki.png) [Image source](https://en.wikipedia.org/wiki/Tic-tac-toe#/media/File:Tic-tac-toe-game-1.svg)

If you haven't played ttt (ever or in a while), I recommend you take a piece of paper and do a couple of rounds with a roommate or relative. You can also play one of the many online versions against a fellow human or an AI!

---

##### Minimax Algorithm
Minimax is an algorithm used in game theory for two-player, sequential, finite-action, deterministic,
zero-sum games of perfect information. Breaking down what that means:  

Two-player
: A game that has two players. Tic-tac-toe is a two-player game; hearts is not.  

Sequential
: A game in which only one player moves at a time. Monopoly is a sequential game; Rochambeau (i.e., rock-paper-scissors) is not.  

Finite-action
: A game in which there is a finite number of legal moves available to a player when it is his turn to move. Battleship is a finite-action game; soccer is not.  

Deterministic
: A game that does not depend at all on chance. Its progress is entirely a function of selected moves. Checkers is deterministic; backgammon is not.  

Zero-sum
: A game in which what is good for one player is equally bad for the other, and vice versa. All the examples given here are zero-sum games.  

Perfect  
information
: A game in which both players witness the entire progression of the game. Chess is a game of perfect information; poker is not.  

<br>
Given that tic-tac-toe meets all of those criteria, we can use the minimax algorithm to determine an optimal move given the following information: the player we are optimizing for and the current board at which the player will make their next move. We will refer to this data as **the game's state**.

Given a game state, minimax will create a game tree whose minimax value can evaluate to either a -1, 0, or 1. A -1 denotes a winning condition for MIN, 0 denotes a tie, and a 1 denotes a winning condition for MAX. The minimax value of a game tree is the value of the root node x, whenever Min moves first,
computed as the minimum value of x’s successors, which are in turn computed as the maximum
value of x’s successors’ successors, and so on. Because the minimax algorithm is recursive, it searches smaller and smaller game trees with each recursive call.

Even for such a small game as Tic Tac Toe, calculating the whole game tree is computationally expensive. Therefore, we will limit our minimax algorithm using MAX_DEPTH.

```text
if the board of the current game state is terminal (i.e., the game is over with that board):
    return the value of the board
    
update game state's current player
assume best minmax value is a tie

if within MAX_DEPTH threshold:
    for each move left in board of the current game state:
        recur minimax on updated board and incremented depth
        the value returned from minimax recursion above is the new minimax value

        if playing MAX:
        	set best minmax value to max of current best minmax value and new minmax value
    	if playing MIN:	
    		set best minmax value to min of current best minmax value and new minmax value

return best minmax value
```

> Subtle differences in your implementation of the minimax algorithm can lead to completely different results so it is crucial that you follow the algorithm exactly as is written above. Furthermore, note the following:
- For our implementation of minimax, player 1 will be MAX and player 2 will be MIN. 
- MAX_DEPTH should be 5 (already defined as a macro)
- At the beginning of your algorithm, assume the best minmax value is a tie

---

#### Your Task {#task}
You are given three files:
- [tic-tac-toe.h](/dds/dd4/template_code/tic-tac-toe.h)
- [tic-tac-toe.cpp](/dds/dd4/template_code/tic-tac-toe.cpp)
- [main.cpp](/dds/dd4/template_code/main.cpp)

Your task is to implement all of the `TODO`s so that you have a tic tac toe game that can be played wth two human players or human vs AI.
- **Do not** change `main.cpp`. The `main()` has already been written for you to enable the AI mode if there's a command line argument or leave the game as a 2 human player game otherwise. 
- **Do not** change `tic-tac-toe.h`.
- Write your implementation of the `//TODO` functions in `tic-tac-toe.cpp`. 
	- You may create additional helper functions as necessary. 
	- **Do not** change the functions that have already been implemented for you
	- **Do not** change the macros that have already been defined for you (can change MAX_DEPTH for testing purposes but make sure to change it back!)

To compile your code, use:
```bash
$ g++ -std=c++11 -Wall main.cpp tic-tac-toe.cpp -o ttt
```

This will generate a command line program that takes in one optional CLA. If the program is executed with no CLA, the game will call the constructor with ai_mode as `false`, which should allow two human players to play together. If there's a CLA present, the game calls the constructor with ai_mode as `true`, which should allow a human player to play against your AI (AI will always be player 2).

---

#### Requirements {#reqs}
Your submission will be **tested and graded by an autograder**, for this reason it cannot be stressed enough that your program must **exactly** follow the assignment specifications:  

1. You should receive **no warning or error messages** upon compilation with the **exact following command**
```bash
	$ g++ -std=c++11 -Wall main.cpp tic-tac-toe.cpp -o ttt
```
2. Your program successfully executes Tic Tac Toe with two human players
3. Your minimax algorithm produces valid moves
4. Your minimax algorithm is implemented as stated above and produces the optimal moves

---

#### Handing in {#submit}
You should have **three files**:
- `tic-tac-toe.h`: class declaration
- `tic-tac-toe.cpp`: implementation of all methods defined in `tic-tac-toe.h`
- `main.cpp`: driver program that takes CLAs and uses the class `ttt_game` to generate output

To submit your solution to Gradescope, select the three required files and use the **drag and drop** option.

---

#### Grade Breakdown {#grading}
This assignment covers the topics of **basic C++ tasks** and **recursive backtracking** and your level of knowledge on them will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 2**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 3**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 4**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Assignment inspired by [Brown University's CS 17](http://cs.brown.edu/courses/csci0170/).
