---
title: Bignum Calculator
asg: Deep Dive 3
permalink: /dd3/
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
✔️ [Long addition](https://www.mathsisfun.com/numbers/addition-column.html)  
✔️ [Long multiplication](https://www.mathsisfun.com/numbers/multiplication-long.html)  
✔️ Classes ([OOP material](/prep#oop))  

---

#### Motivation (Why are we doing this?) {#motivation}
The goal of this deep dive is to provide you an opportunity to determine best uses and applications of **linked lists (all types), stacks, and queues** (non-negotiable), as well as continuing to get you comfortable with **basic C++ tasks**. Namely, in this assignment you'll be:  
✔️ comparing different data structures and algorithms based on efficiency  
✔️ determining the appropriate data structures and algorithms for implementing a solution   

---

#### Background Info {#bgi}

##### Integer Limitations
All programming languages have an upper bound for how large a number type can be and exeeding it may cause errors or unexpected behaviour. In C++, the largest number you can represent as an `int` is `2^31 - 1` or `2147483647`. What happens when you [run the code](http://cpp.sh/4vgct) below?

```cpp
#include <iostream>

int main()
{
    int num_1 = 2147483647;
    int num_2 = 1;
    int sum = num_1 + num_2;
    std::cout << sum;
}
```

While you'd expect to get `2147483648`, running the code above gives you the sum as a negative result: `-2147483648`. This is what's called an *overflow*. Because integers are signed, the first bit represents whether they're a positive number or a negative number. If you change the first bit because you're number is too big, then you accidentally end up with a negative number. Read this [Stack Overflow answer](https://stackoverflow.com/questions/29235436/c-integer-overflow) to get a more in depth reasoning as to why this happens.

##### Bignums
Imagine we live in a world where C++ only has `int`s so the maximum value we can ever represent is `2^31 - 1`, how would we do math with larger numbers? Meet `bignum`. A `bignum` is a number whose value is stored in a data structure in **reverse order**. That is, the integer `12345` would be represented as `5,4,3,2,1` in `bignum` notation.

Why do we reverse the order? If you learned how to do long addition and multiplication by hand, you will remember that we always start at the end of the numbers (with the ones column) and move to the left. This allows us to carry over when values are greater than 9 which means we're able to do the calculation without having to go back and forth each time. To refresh your memory on or learn how to do long addition and long multplication, see the links under the [pre-requisite info](#pre) section.

---

#### Your Task {#task}
You are given three files:
- [bignum_calculator.h](/dds/dd3/template_code/bignum_calculator.h)
- [bignum_calculator.cpp](/dds/dd3/template_code/bignum_calculator.cpp)
- [main.cpp](/dds/dd3/template_code/main.cpp)

Your task is to implement all of the `TODO`s so that you have a calculator that can add and multiply large numbers. 
- **Do not** change `main.cpp`. The `main()` has already been written for you to perform the reading and writing of files that is expected. 
- **Do not** change the function signature of any of the functions we've given you.
- The header file we've given you declares the functions you'll be implementing. 
- The **only thing** you need to do in `bignum_calculator.h` is **change the word "TODO" on line 11** to the representation you'd like to use for your `bignum`s. 
	- Your `bignum` representation must be held in some form of linked list (any type), stack, or queue. 
	- You **may not use vectors or arrays** for the entirety of this assignment.
- Write your implementation of the functions in `bignum_calculator.cpp`. You may create additional helper functions as necessary. 
	- Note that we are using the `string` type to represent numbers in their regular (decimal) notation. Numbers should only be in reverse order while in `bignum` notation.

To compile your code, use:
```bash
$ g++ -std=c++11 -Wall main.cpp bignum_calculator.cpp -o calc
```

This will generate a command line program that takes in the following arguments (CLAs), in this exact order:
```text
<in_file>    file name for the input
<out_file>   file name for the output
```

The `main()` function reads the input file and expects either the word `add` or `multiply` followed by two integers. You can have any combination of add and multiply in any order but each operation must be separated by a new line and the operator word and operand integers must be separated by a space:
```text
add 1 1
multiply 1 1
add 5 3
add 3 5
multiply 2 4
multiply 4 2
```
The output of a working program given an input file containing the text above would look like:
```text
1 + 1 = 1
1 * 1 = 1
5 + 3 = 8
3 + 5 = 8
2 * 4 = 8
4 * 2 = 8
```
The formatting of the output file allows you to easily visually check for errors in your math, which means you **don't need to rely on the autograder to tell you whether your code works or not**. Write your own test input files and check that the math being performed by your calculator is correct.

---

#### Requirements {#reqs}
Your submission will be **tested and graded by an autograder**, for this reason it cannot be stressed enough that your program must **exactly** follow the assignment specifications:  

1. You should receive **no warning or error messages** upon compilation with the **exact following command**
```bash
	$ g++ -std=c++11 -Wall main.cpp bignum_calculator.cpp -o calc
```
2. Your implementation must not use any vectors or arrays
3. Your implementation must perform correct addition on any two positive integers  
	- 3a. Your implementation must perform correct addition on any two positive integers that don't require carrying  
	- 3b. Your implementation must perform correct addition on any two positive integers that do require carrying
4. Your implementation must perform correct multiplication on any two positive integers  
	- 4a. Your implementation must perform correct multiplication on any two positive integers that don't require carrying  
	- 4b. Your implementation must perform correct multiplication on any two positive integers that do require carrying

---

#### Handing in {#submit}
You should have **three files**:
- `bignum_calculator.h`: class declaration
- `bignum_calculator.cpp`: implementation of all methods defined in `bignum_calculator.h`
- `main.cpp`: driver program that takes CLAs and uses the class `bignum_calculator` to generate output

To submit your solution to Gradescope, select the three required files and use the **drag and drop** option.

---

#### Grade Breakdown {#grading}
This assignment covers the **non-negotiable** topics of `linked lists`, `stacks`, and `queues` and your level of knowledge on them will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 3a**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 4a**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 4b**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Assignment inspired by [Brown University's CS 17](http://cs.brown.edu/courses/csci0170/).