---
title: Hash Tables, Chaining, & Open-Addressing
asg: Lab 13
permalink: /lab13/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
The goal of this lab is to provide background on **Hash Tables, Chaining, & Open-Addressing**. 

---

#### Background Info {#bgi}

##### Hash Tables

Hash Tables are a Data Structure that maps keys to values via a Hash Function.

The core concept is to have an array of size *n* with efficient storage/retrieval time.

Let's take a brief look at how these work. Using an example w/ a table size of 5, we have the following:

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     |       |
| 2     |       |
| 3     |       |
| 4     |       |

But how do we store values? We need a Hash Function! 

A Hash Function is (surprise) a function that generates some Hash out of the value to be stored. This is an entire field of research, so we'll keep it simple for now. Let's use the following function:

<center>f(x) = x % n </center>

Let's use it to store the following values: 1, 14, 13, 16

1 % 5 = 1

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     |       |
| 4     |       |

14 % 5 = 4

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     |       |
| 4     | 14    |

13 % 5 = 3

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     | 13    |
| 4     | 14    |

16 % 5 = 1

| Index | Value                  |
| ----- | ---------------------- |
| 0     |                        |
| 1     | 1 <-- already a value! |
| 2     |                        |
| 3     | 13                     |
| 4     | 14                     |

We've found an issue with our new Data Structure! This is known as a Hash Collision. Let's look at methods to combat this.

#### Open Addressing

Open Addressing is a method of collision resolution in hash tables. This method uses **probing** in order to find an open spot in the array to place a value that has encountered a collision. Let's look at a few:

##### Linear Probing

For this method, we simply keep checking the next spot to see if it is available. Let's use the example collision from above and see where we end up:

| Index | Value                  |
| ----- | ---------------------- |
| 0     |                        |
| 1     | 1 <-- already a value! |
| 2     | 16                     |
| 3     | 13                     |
| 4     | 14                     |

Since the very next spot was open, 16 gets placed at index 2.

##### Double Hashing

Another open addressing method is to use double hashing. In this strategy, a second hash function is utilized to re-hash a value that has collisions. Let's view that example from above again using this new definition:

<center>f(x, i) = [(x % n) + (i * f'(x))] % n</center>

<center>f'(x) = x+3</center>

f(16, 0) = [(16 % n) + (0 * 19)] % n = 1

f(16, 1) = [(16 % n) + (1 * 19)] % n = [(1) + 19] % n = 0

| Index | Value |
| ----- | ----- |
| 0     | 16    |
| 1     | 1     |
| 2     |       |
| 3     | 13    |
| 4     | 14    |

A slightly different result than Linear Probing. There are many different strategies for implementing these functions, such as quadratic probing. Let's look at another method entirely.

#### Chaining

In Chaining, instead of an array of keys, we have an array of lists that hold keys. This means probing strategies are not needed, and we just need to push a new value onto the list. For efficiency's sake, we typically push onto the front of the list to maintain O(1) time. Thus, our example values from earlier create the following table: 

| Index | Value   |
| ----- | ------- |
| 0     |         |
| 1     | 16 -> 1 |
| 2     |         |
| 3     | 13      |
| 4     | 14      |



#### Your Task {#task}

Unlike last week's lab, you are in charge of creating all files to complete this assignment.

Note: You will need `doctest.h` and `test.cpp` from last week to use as a base for your test cases. Having a `makefile` wouldn't hurt either!

---

#### Requirements {#reqs}
Your goal for this lab is to complete the following tasks **in order**:

1. Implement a Hash Table that uses Linear Probing. Generate test cases to prove it works.
2. Implement a Hash Table that uses Double Hashing. Generate test cases to prove it works.
3. Implement a Hash Table that uses Chaining. Generate test cases to prove it works.

For **all 3 tasks**, use the following:

- A table of size 15
- 10 values that sufficiently display each strategies unique solution.

---

#### Handing in {#submit}
Please call a TA over to get checked off before leaving your lab section (regardless of how far you got). If you want to continue working on your lab after your lab section, come to [hours](/sp21-archive/staff#sched) to get checked off.

---

#### Grade Breakdown {#grading}
This assignment covers graphs and **Hash Tables, Chaining, & Open-Addressing** and your level of knowledge on them will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 and 2**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 3**


> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sp21-archive/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---