---
title: Priority Queues
asg: Lab 8
permalink: /lab08/
---

On this page:  
✔️ [Motivation](#motivation)  
✔️ [Background Info](#bgi)  
✔️ [Your Task](#task)  
✔️ [Requirements](#reqs)  
✔️ [Handing in](#submit)  
✔️ [Grade Breakdown](#grading)

#### Motivation (Why are we doing this?) {#motivation}
The goal of this lab is to provide you exposure to **Priority Queues**.

---

#### Background Info {#bgi}

Priority Queues are a special form of queue that allow for "cutting in line". This is beneficial when you want to want to enforce a FIFO ordering schema while also allowing more important entries to have priority. 

##### Linked List

We'll be using Linked Lists as our base today. We are familiar with the Node & LinkedList classes as well as how they behave together from [Lab 4](/lab04).

Node objects store Data & a reference to the next Node in the list. The LinkedList maintains a pointer to the first Node in the list ("head") and contains all of the operations that can be performed on the list. LinkedLists can also contain a "tail" pointer that points to the last element in the list.

<p align="center">
  <img src="/labs/lab-08/images/linked-list.png" />
</p>


##### Queue

As a refresher, a Queue is a Linked List with an enforced add/remove order: first-in first-out (FIFO). Elements added to the Queue (enqueued) are placed at the back, and we can only ever remove (dequeue) from the front.

<p align="center">
  <img src="/labs/lab-08/images/queue.png" />
</p>


##### Priority Queue

As you may suspect, a priority queue's roots lies in the Queue data structure, which we have previously seen as a special Linked List.

<p align="center">
  <img src="/labs/lab-08/images/priority-queue.jpg" />
</p>



As a reminder, the Queue data structure is a Linked List with a FIFO ordering schema. Elements leave in the same order they entered.

The Priority Queue has the same properties as the Queue in addition to the following:

- Every element has an associated priority
- Elements with a high priority are dequeued before an element with a lower priority
- Any elements with matching priorities are dequeued in the order they arrived 

Lets compare the performance of a Queue with a Priority Queue:

|         | Queue | Enqueue |
| :-----: | :---: | :-----: |
| Enqueue | O(1)  |  O(n)   |
| Dequeue | O(1)  |  O(1)   |
|  Peek   | O(1)  |  O(1)   |

They are very similar, but Enqueue jumps from a constant time operation to a linear time operation. Yikes!

**Can you explain why this might be the case?**

<details>
    <summary>Click here to reveal the answer!</summary>

    To insert elements into a P-Queue, we must iterate over the queue until we find the proper location. Worst cast would be adding an element with the lowest priority, so we would need to traverse the entire list.

</details>

But fret not, there is a better way to implement a Priority Queue! But we'll learn about those next week.

---

#### Your Task {#task}

You are given code for a working Linked List (the solution to Lab 4!) and are tasked with modifying it to be a Queue, then a Priority Queue.

[Lab 4 Solution](/labs/lab-08/lab-04-solution.zip)

---

#### Requirements {#reqs}  

1. Go through **all** of the classes & functions you will need to change and write comments explaining what needs changing for both problems. Be detailed!
2. Convert the Linked List code into a Queue class. Create test cases in main() to show FIFO is enforced.
3. Copy the code for your Queue program into another folder and convert it into a Priority Queue. Once more, create test cases in main() to show it works properly.

---

#### Handing in {#submit}
Please call a TA over to get checked off before leaving your lab section (regardless of how far you got). If you want to continue working on your lab after your lab section, come to [hours](/staff#sched) to get checked off.

---

#### Grade Breakdown {#grading}
This assignment covers the topic of **priority queues and heaps** and your level of knowledge on it will be assessed as follows: 
- To demonstrate an `awareness` of these topics, you must:
    - Successfully meet [requirement](#reqs) **1**
- To demonstrate an `understanding` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 and 2**
- To demonstrate `competence` of these topics, you must:
    - Successfully meet [requirements](#reqs) **1 through 3**

> To receive any credit at all, you **must abide by our [Collaboration and Academic Honesty Policy](/policies/#integrity)**. Failure to do so may result in a failing grade in the class and/or further disciplinary action.