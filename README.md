# C-Data-Structures-Project-1
Comparing runtime of operations on a sorted list/array and an unsorted one
When given n numbers as input, there are many operations/questions/queries that you can
perform/ask about the n numbers. The time to answer these queries or perform the operations
vary depending on how the numbers are spread out in the given order – pattern in which they are
given. One way to speed up the query time is to vary the pattern of these given numbers to an
orderly fashion – increasing or decreasing order.
Given a sequence of n numbers as input in no particular order, the goal is to re order the numbers
for an output where the numbers are all in increasing or decreasing order. This is the definition
for Sorting a set of n numbers.
Once we sort the given numbers into an order, the queries, or operations that we can perform can
be faster (at least for a specific set of them if not all operations/queries). For example, once we
sort, finding the median of the n numbers can and will be faster but time to find the mean will
not change.
You will be comparing the time taken for performing queries and operations between an
unsorted set of random numbers and performing the same query/operation on a sorted version of
the same set of numbers.
You are given a set of randomly generated numbers that is first stored in a dynamic array (A).
Once this is stored, you will have to sort this array and store the sorted array in a different array
(B). You can use any sorting algorithm to sort (we will be providing you with a sorting algorithm
as well).
Queries:
• Find/search the given element in both the sorted and unsorted arrays.
o In array B (sorted array), you can use binary search to find the value.
o In array A, you must do a linear search.
• SumPairs: Given an integer target, return the two numbers such that they add up to the
target.
Operations:
• Remove the given element from both the arrays A and B.
o Once you remove the element, you must left shift the values to the right of the
empty space so that the empty spaces as we remove more elements are maintained
to the right end of the array.
• Insertion: Insert the given element into both the arrays A and B.
o In array B (sorted array), you must insert the value into the right position.
o In array A, you may insert it at the end of the array.
Assumptions:
• Number of removals will be always less than the number of insertions. So there is no
need to reallocate the arrays.
• There will not be any duplicates in the given set of random numbers.
• Keep up with the FAQ discussion board for project 1 on canvas as more assumptions and
conversations will be continued there.
