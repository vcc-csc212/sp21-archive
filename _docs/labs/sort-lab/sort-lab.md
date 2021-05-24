---
title: Sorting Lab
asg: Optional Lab (to get competence on topic #2)
permalink: /sort-lab/
---

> **IMPORTANT:** You may work individually or in pairs (no more than 2 people total)

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)  

#### Motivation (Why are we doing this?) {#motivation}
The goal of this deep dive is to provide an opportunity to demonstrage your knowledge of `Sorting Algos (Implementation & Analysis)`, including:  

✔️ Implementation of insertion sort  
✔️ Implementation of selection sort  
✔️ Implementation and analysis of merge sort  
✔️ Implementation and analysis of quick sort  

---

#### Background Info {#bgi}
Sorting algorithms are used to rearrange a list or array of elements according to a **comparison operator** on the elements. The comparison operator in a sorting algorithm decides the new order of elements. Some are simple, but some are more ellaborate, requiring use of things like helper functions.

---

#### Your Task {#task}
Complete the implementation of the sorting algorithms in `sorting-lab.cpp`. Pay attention to the **hints in the code**. Refer to previous material as needed:
- [Insertion and selection sort implementation material](/sp21-archive/wk2#thurs)
- [Insertion and selection sort analysis material](/sp21-archive/wk3#tues)
- [Mergesort material](/sp21-archive/wk6#tues)
- [Quicksort material](/sp21-archive/wk7#tues)
- [Class slides](/sp21-archive/slides)

Similar to our recent labs, you'll be using a makefile and unit testing for this lab. Make sure to download all files:
- [sorting-lab.cpp](/sp21-archive/labs/sort-lab/template-code/sorting-lab.cpp)
- [sorting-lab.h](/sp21-archive/labs/sort-lab/template-code/sorting-lab.h)
- [test.cpp](/sp21-archive/labs/sort-lab/template-code/test.cpp)
- [doctest.h](/sp21-archive/labs/sort-lab/template-code/doctest.h)
- [makefile](/sp21-archive/labs/sort-lab/template-code/makefile)

---

#### Requirements {#reqs}
Your goal for this lab is to complete the following tasks:

1. Finish each sorting algorithm by implementing the missing code (evaluate correctness based on all tests passing)
2. Above the declaration of the respective function, in a comment, explain the time complexity of `merge()` and `partition()` in terms of `low` and `high`.

---

#### Handing in {#submit}
Please get this optional lab checked off at hours or via a private Piazza post.

---

#### Grade Breakdown {#grading}
This assignment covers the **non-negotiable topic** of `Sorting Algos (Implementation & Analysis)` and your level of knowledge on them will be assessed as follows:
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 2**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/sp21-archive/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.

---

Assignment hints and template code brought to you by Evan Russell.