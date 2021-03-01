---
title: Advanced Recursion
asg: Lab 06
permalink: /lab06/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
The goal of this deep dive is to provide some insight into **advanced recursive algorithms**.

---

#### Background Info {#bgi}

Fractals are geometric figures in which each part has the same statistical character as the entire figure. In other words, the same patterns repeated at varying scales. Here are a few!



> Sierpinski Carpet

![image](/labs/lab-06/images/sierpinskicarpet.jpg)



> Sierpinski Triangle

![image](/labs/lab-06/images/sierpinski_triangle.png)



> Koch Snowflake

![image](/labs/lab-06/images/koch_snowflake.png)



Can you find the repeating patterns in each of these fractals? 

Sierpinski Carpet: A square with 8 smaller squares 1/3 the size are placed around it.

Sierpinski Triangle: An equilateral triangle subdivided into 4 smaller equilateral triangles, with the inner triangle removed.

Koch Snowflake: An equilateral triangle where each edge gets a triangle placed 1/3 the size of the original, and has its base removed.

Now that we understand the pattern, we need to learn how to implement them! To this effect, we will be utilizing 'L-systems'.

##### Lindenmayer Systems (L-Systems)

An 'L-system' is an alphabet of symbols that form strings, which represent a collection of production rules. In this case, we will be the following 'L-system':

F : Move forward

\- : Turn left by some degree

\+: Turn right by some degree

So, a valid string for this system could be "F + F + F + F". If this is run with a turn degree of 90, what shape would we have generated?

Similarly, what shape does the following string with a turn degree of 60 generate? "F - F - F"?

---

#### Your Task {#task}

You will implement both of the fractal shapes above by utilizing an 'L-system'. Your task is to create recursive functions to solve each that generate the string necessary to draw the shape. You have been supplied with some skeleton code to get you started, as well as a python script to convert a generated string into a .png image representation.

Here are some animations to help you in determining the rules for your strings:

![image](/labs/lab-06/images/sierpinski_triangle_animation.gif)

![image](/labs/lab-06/images/koch_snowflake_animation.gif)

##### Notes

- To use the python file: `python3 l-system-plotter.py l-system.txt <output file name> <degree for turns>  `
  - degree should be 60 for both of these problems!
- Get a feeling for the string you should be generating BEFORE you start coding.


---

#### Requirements {#reqs}
1. Outline an algorithm to create an L-System for the Koch Snowflake.
2. Complete the function to produce a Koch Snowflake
3. Complete the function to produce a Sierpinski Triangle
---

#### Handing in {#submit}
Please call a TA over to get checked off before leaving your lab section (regardless of how far you got). If you want to continue working on your lab after your lab section, come to [hours](/staff#sched) to get checked off.

---

#### Grade Breakdown {#grading}
This assignment covers **advanced recursion** and your level of knowledge on them will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirement](#reqs) **1**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 and 2**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 3**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---


Original assignment by [Dr. Marco Alvarez](https://homepage.cs.uri.edu/~malvarez/), used and modified with permission.