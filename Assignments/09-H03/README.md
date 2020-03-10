## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)
#### zachary Kingcade
<br>

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.
&nbsp;&nbsp; Fastest:
&nbsp;&nbsp;&nbsp;&nbsp; O(1)
&nbsp;&nbsp;&nbsp;&nbsp; O(log n)
&nbsp;&nbsp;&nbsp;&nbsp; O(n)
&nbsp;&nbsp;&nbsp;&nbsp; O(n log n)
&nbsp;&nbsp;&nbsp;&nbsp; O(n<sup>2</sup>)
&nbsp;&nbsp;&nbsp;&nbsp; O(n!)
&nbsp;&nbsp; Slowest
<br>

- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm runs in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program?
&nbsp;&nbsp;&nbsp;&nbsp; n<sup>2</sup>    = 10
&nbsp;&nbsp;&nbsp;&nbsp; n = $\sqrt{10}$
&nbsp;&nbsp; so now that we've isolated n
&nbsp;&nbsp;&nbsp;&nbsp; (2n)<sup>2</sup> = (2 * $\sqrt{10}$)<sup>2</sup>
&nbsp;&nbsp;&nbsp;&nbsp; (2 * $\sqrt{10}$)<sup>2</sup> = (2<sup>2</sup> * $\sqrt{10}$<sup>2</sup>)
&nbsp;&nbsp;&nbsp;&nbsp; (2<sup>2</sup> * $\sqrt{10}$<sup>2</sup>) = (4 * 10)
&nbsp;&nbsp;&nbsp;&nbsp; (4 * 10) = 40
&nbsp;&nbsp; so it would take 40 seconds if you doubled the data set size
<br>

Using Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
1.Finding the max element in an unordered stack would require _____________ operations?
&nbsp;&nbsp; O(n)
2. Finding the min element in an unordered queue would require _____________ operations?
&nbsp;&nbsp; O(n)
3. Finding some element in some Binary Search Tree would require _____________ operations?
&nbsp;&nbsp; O(h)
4. Finding some element in a balanced Binary Search Tree would require _____________ operations?
&nbsp;&nbsp; O(log n)
5. Finding some element in an ordered linked list would require _____________ operations (worst case)?
&nbsp;&nbsp; O(n)
6. Finding some element in an ordered linked list would require _____________ operations (average case)?
&nbsp;&nbsp;  O(n) - I would generally consider this n/2 but since we throw away constants it just becomes n
7. Finding some element in an unordered linked list would require _____________ operations (worst case)?
&nbsp;&nbsp; O(n)
<br>

8. For each of the following, count the number of operations where some_statement is executed based on the loops

```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
&nbsp;&nbsp; first loop is n, second loop is n, so nxn
&nbsp;&nbsp; O(n<sup>2</sup>)

```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
&nbsp;&nbsp; first loop is n/2, second loop is n, so n/2 x n
&nbsp;&nbsp; however we throw away constants and n/2 is the same as n * 1/2
&nbsp;&nbsp; making our final notation nxn
&nbsp;&nbsp; O(n<sup>2</sup>)
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```
&nbsp;&nbsp; first loop is (log n), second loop is n so (log n)xn
&nbsp;&nbsp; O(n log n)
<br>

At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?
&nbsp;&nbsp; it would take 10 searches since log(1023) $\approx$ 10
&nbsp;&nbsp; (is actually 9.99859042975 but we can't do part of an opertaion now can we)
<br>

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
&nbsp;&nbsp;&nbsp;&nbsp; Linked-List
2. You need to store undo/redo operations in a word processor.
&nbsp;&nbsp;&nbsp;&nbsp; Stack
3. You need to evaluate an expression (i.e., parse).
&nbsp;&nbsp;&nbsp;&nbsp; Array
4. You need to store the friendship information on a social networking site. I.e., who is friends with who.
&nbsp;&nbsp;&nbsp;&nbsp; Graph
5. You need to store an image (1000 by 1000 pixels) as a bitmap.
&nbsp;&nbsp;&nbsp;&nbsp; 2D Array
6. To implement printer spooler so that jobs can be printed in the order of their arrival.
&nbsp;&nbsp;&nbsp;&nbsp; Queue
7. To implement back functionality in the internet browser.
&nbsp;&nbsp;&nbsp;&nbsp; Stack
8. To store the possible moves in a chess game.
&nbsp;&nbsp;&nbsp;&nbsp; Sets
9. To store a set of fixed key words which are referenced very frequently.
&nbsp;&nbsp;&nbsp;&nbsp; Hash Table
10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)
&nbsp;&nbsp;&nbsp;&nbsp; Queue
11. To store the genealogy information of biological species.
&nbsp;&nbsp;&nbsp;&nbsp; Tree
12. To store an alphabetized list of names in order to look up quickly.
&nbsp;&nbsp;&nbsp;&nbsp; Array


## Deliverables

- Edit this file and add your answers using markdown!
- Create a folder called `H03` in your assignments folder.
- Put a copy of your markdown file in this folder, and call it README.md.
- Upload to github sometime close to the due date.
- Print out your banner ON ITS OWN PAGE

```
H03
3013
LASTNAME
```

- Print out a hard copy of the file as well. Do not print directly from github. Either use `gitprint` or make it a pdf and print it.
- Make sure you answer thoroughly using complexities where appropriate and/or explaining your choices etc.
