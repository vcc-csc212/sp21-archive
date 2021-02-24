---
title: Debugging & Problem Solving
asg: Lab 05
permalink: /lab05/
---

> **Note**: This Lab differs from the others as it is **due at the end of this session!** You **cannot** get checked off for more credit at TA hours for this lab. What you get by the end of the session is what you get for the **problem-solving** topic.

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
The goal of this deep dive is to provide a better understanding of debuggers and to give you experience with problem solving and translating that into code. This will **help you be able to start DDs on your own without feeling overwhelmed**. This type of **problem-solving takes practice** and that’s the whole point of this lab— to give you practice and help you **become a better problem-solver and computer scientist**.

---

#### Background Info {#bgi}

##### 1. Debugging

First, lets make a quick *hello world* program. With that file, we'll be able to explore some basic features of the CS50 IDE debugger (or whatever your IDE of choice is).

Create and save a `hello.cpp` program with the following contents.


```c++
#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl;
	return 0;
}
```


Now you will run this program in debug mode; allowing you to run code line by line, or chunk by chunk, depending on where your breakpoints are. While the code is running, you can update variables and function calls, thus allowing you to find errors in your code more easily.

##### 1.1 Setting a Breakpoint

Before you start debugging you must set a breakpoint in your code. In debug mode, your program will run normally until it reaches the breakpoint. You are now in control of when your program executes its lines of code. To set a breakpoint, click  on the light gray space in your file window that is to the left of the numbers column, on the line that you wish to start debugging. A big red circle should appear after clicking once, with an example shown below:

<center><img src="/labs/lab-05/images/breakpoint.png" ></center>

##### 1.2 Running in Debug Mode

Now that you've set a breakpoint, we must run the program in debug mode. You can do this by running the `debug50` command. However, in order to run debug50 we need to compile our code with deugging flags, this is as simple as adding the -g flag in the compile command. Using `g++ -g hello.cpp -o hello` should produce an adequate exectable. For our example the following will run your program in debugging mode:

```bash
$ debug50 hello
```

If you're using a different IDE, chances are there is a "Debug and Run" mode in the top menu.

##### 1.3 Debugging "Hello World"

You should notice that your program stops executing at the breakpoint, and the line with the breakpoint is highlighted yellow. When debugging, the highlighted line is the next line of code to be executed. To the right you should see the debugging window, as shown below.   

<center><img src="/labs/lab-05/images/debug-window.png" ></center>

The top row of buttons allow you to navigate and execute your code. These icons are consistent across IDEs. From Left to Right:
- The play button (sideways triangle), or the resume button, will stop debugging and run your program normally until it reaches another breakpoint, end of program, or a runtime error, and then starts debugging again;
- The Step Over (curved arrow down) and Step Into (straight arrow down) buttons will both execute the next line of code. They perform differently when the next line of code includes a function. The Step Over button will execute the function call completely and finish executing the current line. The Step Into button will instead move the debugger to that function's code and continue debugging there;
- The Step Out (arrow up) button can be pressed when you are inside a function call to finish the function call and return to the original line of code that called that function;
- The Deactivate All Breakpoints (empty circle) button is self explanatory.  

##### 1.4 Debugging Another Program

Before we debug another program with our debugger tool, let's become the debugger ourselves. Take look at the code below and trace this program on paper, keeping track of each variable value.

```c++

#include <iostream>

int pow(int, int);

int main() {
	int x = 2;
	int y = 4;
	int z = pow(x, y);
	std::cout << x << "^" << y << "=" << z << std::endl;
	return 0;
}

/* A Naive method for calculating powers */
int pow(int a, int b) {
	int result = 1;
	while (b != 0) {
		result *= a;
		--b;
	}
	return result;
}

```

Let's take a look at how you did. Now, use the CS50 debugging tool to trace the values of this program's variables. Set a breakpoint on the first line of main() `int x = 2;` and run the debugger.

##### 2. Problem Solving

##### 2.1 Algorithms

An `algorithm` is a method or a process followed to solve a problem. You might perform an algorithm every day without thinking about it. A problem can be solved by many different algorithms. A given algorithm solves only one problem.

By definition, something can only be called an algorithm if it has all of the following properties.

* **It must be correct**. In other words, it must preform a desired behavior or yield an expected result. Algorithms are intentional with a specific end-goal in mind.
* **It is composed of a series of concrete steps**. Concrete means that the action described by that step is completely understood --- and doable --- by the person or machine that must perform the algorithm. Each step must also be doable in a finite amount of time. Thus, the algorithm gives us a "recipe" for solving the problem by performing a series of steps, where each such step is within our capacity to perform. The ability to perform a step can depend on who or what is intended to execute the recipe. For example, the steps of a cookie recipe in a cookbook might be considered sufficiently concrete for instructing a human cook, but not for programming an automated cookie-making factory.
* **There can be no ambiguity as to which step will be performed next**. Often it is the next step of the algorithm description. Selection (e.g., the if statement) is normally a part of any language for describing algorithms. Selection allows a choice for which step will be performed next, but the selection process is unambiguous at the time when the choice is made.
* **It must be composed of a finite number of steps**. If the description for the algorithm were made up of an infinite number of steps, we could never hope to write it down, nor implement it as a computer program. Most languages for describing algorithms (including English and "pseudocode") provide some way to perform repeated actions, known as iteration. Examples of iteration in programming languages include the while and for loop constructs. Iteration allows for short descriptions, with the number of steps actually performed controlled by the input.
* **It must terminate**. In other words, it may not go into an infinite loop.

##### 2.2 Problem Design Concepts

Programmers commonly deal with problems, algorithms, and computer programs. These are three distinct concepts.

In this context, a problem is a task to be performed. It is best thought of in terms of inputs and matching outputs. A problem definition should not include any constraints on how the problem is to be solved. The solution method should be developed only after the problem is precisely defined and thoroughly understood. 


<center><img src="/labs/lab-05/images/problem.png" width="450px"></center>

*Image from: Problem Solving with C++, 10th Edition, Walter Savitch*

As you can see, the problem solving and implementation phase are separated into different boxes. That's because these processes are somewhat independent and don't explicitly depend on each other.

Take what we now know about algorithms and consider some problem design strategies that can be implemented without any consideration of code, programming, or computer science. Brainstorm and provide an example with your group as a comment in your lab code file.

---

#### Your Task {#task}

Solve each of the following practice programming interview problems. After you get a working solution for each problem, calculate its Big-Oh run time. 

> Note: You **must** solve all of these problems manually! You cannot use code you find online, nor can you use a built-in library function that trivializes the problem!

1. Find the missing number in a given integer array from 1 to n. Assume the array is of size n-1. Assume the array is shuffled. 
2. Find the smallest & largest numbers in an integer array. Assume the array is shuffled.
3. Find the first non repeated character of a given string.
4. Find the middle element of a linked list.


---

#### Requirements {#reqs}
1. Solve any one of the above problems.
2. Solve any two of the above problems.
3. Solve any three of the above problems.

---

#### Handing in {#submit}
Please call a TA over to get checked off before leaving your lab section (regardless of how far you got). This Lab differs from the others as it is **due at the end of this session!**

> You **cannot** get checked off for more credit at TA hours for this lab. What you get by the end of the session is what you get for the **problem-solving** topic.

---

#### Grade Breakdown {#grading}
This assignment covers **problem solving** and your level of knowledge on them will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirement](#reqs) **1**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirement](#reqs) **2**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirement](#reqs) **3**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Original assignment by [Dr. Marco Alvarez](https://homepage.cs.uri.edu/~malvarez/), used and modified with permission.