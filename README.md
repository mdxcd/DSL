# Data Structures Lab (DSL)

A collection of C programs, terminal execution outputs, and formatted PDF lab reports for Data Structures laboratory assignments (`LAB1`–`LAB8`), practice exercises, and sessional work.

---

## Repository Structure

```text
.
├── LAB1/           # Dynamic Arrays & Structures
├── LAB2/           # Polynomials & Sparse Matrix Triplet Representation
├── LAB3/           # Singly Linked Lists
├── LAB4/           # Doubly Linked Lists, Merging & Circular Linked Lists
├── LAB5/           # Stack Applications
├── LAB6/           # Linear, Circular & Priority Queues (+ PDF & outputs/)
├── LAB7/           # Binary Trees
├── LAB8/           # Binary Search Tree
├── Practice/       
└── SESSIONAL/      # Sessional Exam
```

---

## Lab Index

### [LAB 1](LAB1/) — Dynamic Arrays & Structures
- [`p1.c`](LAB1/p1.c) — Dynamic array operations: find min/max, search key position, and separate even/odd elements
- [`p2.c`](LAB1/p2.c) — Find the largest element and its frequency in a dynamic array using a single loop
- [`p3.c`](LAB1/p3.c) — Count and display elements between two bounds `a` and `b` (inclusive) in an unsorted dynamic array
- [`p4.c`](LAB1/p4.c) — Find the second smallest and second largest elements in a dynamic array
- [`p5.c`](LAB1/p5.c) — Store and display `n` student records (roll no, name, gender, marks) using an array of structures
- [`p6.c`](LAB1/p6.c) — Add two distances (`km` and `m`) using pointers to structures
- **Report:** [`LAB1 - Md Mobid - 2505031.pdf`](LAB1/LAB1%20-%20Md%20Mobid%20-%202505031.pdf)

### [LAB 2](LAB2/) — Polynomials & Sparse Matrices
- [`p1.c`](LAB2/p1.c) — Represent and display a polynomial using an array
- [`p2.c`](LAB2/p2.c) — Addition of two polynomials using arrays
- [`p3.c`](LAB2/p3.c) — Multiplication of two polynomials using arrays
- [`p4.c`](LAB2/p4.c) — Triplet representation of a sparse matrix
- [`p5.c`](LAB2/p5.c) — Addition of two sparse matrices using triplet format
- [`p6.c`](LAB2/p6.c) — Transpose of a sparse matrix using triplet format
- **Report:** [`LAB2 - Md Mobid - 2505031.pdf`](LAB2/LAB2%20-%20Md%20Mobid%20-%202505031.pdf)

### [LAB 3](LAB3/) — Singly Linked Lists
- [`p1.c`](LAB3/p1.c) — Menu-driven singly linked list: create, display, display alternate nodes, find max/min, insert, delete, reverse, and find middle element
- [`p2.c`](LAB3/p2.c) — Concatenate two singly linked lists
- **Report:** [`LAB3 - Md Mobid - 2505031.pdf`](LAB3/LAB3%20-%20Md%20Mobid%20-%202505031.pdf)

### [LAB 4](LAB4/) — Doubly & Circular Linked Lists
- [`p1.c`](LAB4/p1.c) — Menu-driven doubly linked list: create, forward/backward display, insert, and delete (beginning, last, position)
- [`p4.c`](LAB4/p4.c) — Concatenation of two doubly linked lists
- [`p5.c`](LAB4/p5.c) — Merge two sorted singly linked lists into one sorted list
- [`p6.c`](LAB4/p6.c) — Create a circular linked list and count even and odd numbers
- **Report:** [`LAB4 - Md Mobid - 2505031.pdf`](LAB4/LAB4%20-%20Md%20Mobid%20-%202505031.pdf)

### [LAB 5](LAB5/) — Stacks & Applications
- [`p1.c`](LAB5/p1.c) — Menu-driven stack using array (`isEmpty`, `display`, `push`, `pop`)
- [`p2.c`](LAB5/p2.c) — Menu-driven stack using singly linked list (`isEmpty`, `display`, `push`, `pop`)
- [`p3.c`](LAB5/p3.c) — Decimal to binary conversion using stack
- [`p4.c`](LAB5/p4.c) — Reverse a string using stack
- [`p5.c`](LAB5/p5.c) — Balanced brackets checker using stack
- **Report:** [`LAB5 - Md Mobid - 2505031.pdf`](LAB5/LAB5%20-%20Md%20Mobid%20-%202505031.pdf)

### [LAB 6](LAB6/) — Queues
- [`p1.c`](LAB6/p1.c) — Menu-driven queue using static array (`enqueue`, `dequeue`, `peek`, `display`, `isEmpty`, `isFull`)
- [`p2.c`](LAB6/p2.c) — Menu-driven queue using linked list (`enqueue`, `dequeue`, `peek`, `display`, `isEmpty`)
- [`p3.c`](LAB6/p3.c) — Menu-driven circular queue using static array (`enqueue`, `dequeue`, `peek`, `display`, `isEmpty`, `isFull`)
- [`p4.c`](LAB6/p4.c) — Menu-driven priority queue using linked list (`enqueue`, `dequeue`, `peek`, `display`, `isEmpty`)
- **Report:** [`LAB6 - Md Mobid - 2505031.pdf`](LAB6/LAB6%20-%20Md%20Mobid%20-%202505031.pdf)

### [LAB 7](LAB7/) — Binary Trees
- [`p1.c`](LAB7/p1.c) — Construct and traverse a binary tree using array representation
- [`p2.c`](LAB7/p2.c) — Construct a binary tree using linked list with `InOrder`, `PreOrder`, and `PostOrder` traversals
- [`p3.c`](LAB7/p3.c) — Count the number of leaf nodes in a binary tree using linked list
- **Report:** [`LAB7 - Md Mobid - 2505031.pdf`](LAB7/LAB7%20-%20Md%20Mobid%20-%202505031.pdf)

### [LAB 8](LAB8/) — Binary Search Tree (BST)
- [`p1.c`](LAB8/p1.c) — Binary Search Tree implementation with `insert_node`, `delete_node`, `find_min`, `find_max`, `InOrder`, `PreOrder`, and `PostOrder`
- **Report:** [`LAB8 - Md Mobid - 2505031.pdf`](LAB8/LAB8%20-%20Md%20Mobid%20-%202505031.pdf)

### [Practice](Practice/) & [SESSIONAL](SESSIONAL/)
- [`Practice/p1.c`](Practice/p1.c) — Linear search
- [`Practice/p2.c`](Practice/p2.c) — Binary search
- [`SESSIONAL/p.c`](SESSIONAL/p.c) — Menu-driven queue using array (`enqueue`, `dequeue`, `peek`, `display`)

---

## Compiling and Running

Compile any program with `gcc` and run the generated executable:

```bash
gcc -Wall LAB8/p1.c -o p1
./p1
```

On Windows (PowerShell):

```powershell
gcc -Wall LAB8\p1.c -o p1.exe
.\p1.exe
```

