# Analysis and Design of Algorithms
> Collection of all programs for ADA lab 2025

## Index
- [x] Quicksort
    - sorting of an array using a pivot ensuring the elements to the left of the pivot are smaller than the pivot and elements right of pivot are larger than it
    - The pivot is put in the position where it it should be when the whole array is sorted
    - Uses a recursive structure to sort each side split along the index of the pivot\
    <img src="./plot/graphs/quicksort.png" alt="quicksort" width="600px"/>
- [x] Iterative Quicksort
    - Quicksort in iterative form
    - Reduces the size of stack used
    <img src="./plot/graphs/iterative_quicksort.png" alt="iterative quicksort" width="600px"/>
- [x] peak - Peak finding algorights for 1D and 2D arrays
    - Finding an element which is >= to its neighbours
    - [x] 1D 
        - Implemented using algo similar to Binary Search
    - [x] 2D
        - Implemented using algo similar to Binary Search but works in a 2D array
- [x] Magic square(odd size) - Sum of all rows, columns and diagonals is equals
    - Creates a square matrix where the sum of all colums, rows and diagonals is equal
    - Follows a set pattern in where the numbers increase in a diagonal upwards to the left and goes down one when number is a multiple of the size
    <img src="./plot/graphs/magic_square.png" alt="magic square" width="600px" />
- [x] Cosine Similarity
    - Find out the similarity between two documents by checking the number of time each word occours in each file
    - Each files words are treated like a vector and the angle between the vectors created from the two file give the value for cosQ which tells us the similarity between the files
- [x] Fractional Knapsack
    - Problem involving the calculation of max(here price) that can be gotten from a set of values
    - We sort the array according to the metric we need(here we sort 3 time, according to profit, weight and ratio of profit/weight) and then pick the items in non-increasing manner
    - The fractional part allows us to pick out items in fraction
        - For example if we have a capacity of 10 and the item weights 20 we can take out 10 out the weight instead of leaving that item and going to the next
    <img src="./plot/graphs/knapsack.png" alt="knapsack" width="600px" />
- [x] Job Scheduling
    - Schedule all jobs for the day ensuring maximum number of jobs are done
    - FCFS, SJF and sorting by final_time used
    <img src="./plot/graphs/scheduling.png" alt="knapsack" width="600px" />
    - Time complexity of SJF is very high due to checking of availibility of that job
    <img src="./plot/graphs/scheduling_time.png" alt="knapsack" width="600px" />
- [ ] Matrix multiplication
    - [x] Conventional Method
        - Using divide and conquer to break the matrix into smaller parts and multiplying them to get the resulting martix
    - [ ] Strassen's matrix multiplication
        - turn the O(n<sup>3</sup>) algo into a O(n<sup>2.81</sup>) algo
- [ ] Polygon Hull
    - [x] QuickHull
        - [x] Using aproch similar to quicksort we divide the problem into multiple triangles and seperately solve them\
        <img src="./plot/graphs/quickhull.png" alt="quickhull" width="600px" />
- [ ] Find all possible triangles
- [ ] Find if point lies in a triangle
