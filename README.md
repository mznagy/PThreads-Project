## Resources

You may learn about threads here : https://www.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/4_Threads

You may learn about POSIX threads here : https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html

You may learn about Programming with threads :

1) [Threads in C - Part 1](https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=3)

2) [Threads in C - Part 2](https://www.youtube.com/watch?v=It0OFCbbTJE&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=3)

# Problem Statement
It is required to implement two popular algorithms as multi-threaded ones. They are as follows:
## Matrix Multiplication
It is required to implement two variations of this algorithm:
1. The computation of each element of the output matrix happens in a thread.
2. The computation of each row of the output matrix happens in a thread.
For both variations, you have to compute the elapsed time for each of them, compare them, and justify your answer.
## Merge Sort
Merge sort is an O (n log n) comparison-based sorting algorithm. It is a divide-and-conquer algorithm. Conceptually, a merge sort
works as follows:
If the list is of length 0 or 1, then it is already sorted. Otherwise:
1. Divide the unsorted list into two sub-lists of about half the size.
2. Sort each sub-list recursively by re-applying the merge sort.
3. Merge the two sub-lists back into one sorted list
So you are required to implement it using pthreads. Each time the list is divided; two threads are created to do merge-sort on each
half separately. This step is repeated recursively until each sub-list has only one element.
