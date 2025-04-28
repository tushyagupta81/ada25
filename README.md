# Analysis and Design of Algorithms
> Collection of all programs for ADA lab 2025

## Index
- [x] Quicksort
    - sorting of an array using a pivot ensuring the elements to the left of the pivot are smaller than the pivot and elements right of pivot are larger than it
    - The pivot is put in the position where it it should be when the whole array is sorted
    - Uses a recursive structure to sort each side split along the index of the pivot
    <img src="./plot/graphs/quicksort.png" alt="quicksort" width="600px"/>
- [x] Iterative Quicksort
    - Similar to recursive quicksort but uses a stack to maintain the index of the places where the pivot cut the array
    - Quicksort in iterative form
    - Reduces the size of stack used
    <img src="./plot/graphs/iterative_quicksort.png" alt="iterative quicksort" width="600px"/>
- [x] Comparing stack size of iterative vs recursive quicksort
    <img src="./plot/graphs/compare_quicksort.png" alt="Comparing quicksort stack size" width="600px"/>
- [x] Peak - Peak finding algorights for 1D and 2D arrays
    - Finding an element which is larger to all its neighbours
    - [x] 1D 
        - Implemented using algo similar to Binary Search
    <img src="./plot/graphs/peak1d.png" alt="peak1d" width="600px"/>
    - [x] 2D
        - Implemented using algo similar to Binary Search but works in a 2D array
    <img src="./plot/graphs/peak2d.png" alt="peak2d" width="600px"/>
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
- [x] Matrix multiplication
    - [x] Conventional Method
        - Using divide and conquer to break the matrix into smaller parts and multiplying them to get the resulting martix
    - [x] Strassen's matrix multiplication
        - turn the O(n<sup>3</sup>) algo into a O(n<sup>2.81</sup>) algo
    <img src="./plot/graphs/strassens.png" alt="strassens" width="600px" />
- [x] Polygon Hull
    - [x] QuickHull
        - [x] Using aproch similar to quicksort we divide the problem into multiple triangles and seperately solve them\
        <img src="./plot/graphs/quickhull.png" alt="quickhull" width="600px" />
- [x] Dijkastra
    - Find the shortest path from source to sink

- [x] Kruskals
    - Minimum spanning tree
- [x] Prims
    - Finds one minimum edge using the merge sort technique and then find the shortest edge from the 2 selected vertex’s
    - keeps on adding the shortest edges that extend from our visited vertex’s that don’t go to our visited vertexs
    - Minimum spanning tree\
    <img src="./plot/graphs/prims_graph.png" alt="prims graph" width="400px" />
    <img src="./plot/graphs/prims_tree.png" alt="prims tree" width="400px" />
- [x] All Pair Shortest Path(Floyd-Warshall Algorithm)
    - We find the minimum cost to go from any vertex to any other vertex
    - We store the intermidiate result in the original adjency matrix or create a new one
        - The values are updated if we find a new minimum cost
- [x] Multistage graph
    - A grpah that has a single starting node and a single ending node
    - Find out the cost to go to from source to sink from any node
    - [x] Forward method\
        <img src="./plot/graphs/forward_multistage.png" alt="forward_multistage" width="600px" />
    - [x] Backword method\
        <img src="./plot/graphs/backward_multistage.png" alt="backward_multistage" width="600px" />
- [x] Matrix Chain Multiplication
    - Find the order fo multiplication to reduce the number of scalar multiplications
    - Find out the minimum cost of matrix multiplication by reducing the number of scalar multiplication needed
    - Bundles together matrix multiplications using their sizes and shows the optimal order of multiplication
    - Creates a 2D array containing the cost to multiply any combination of the matrixes
- [x] Knapsack using sets(merge purge)
    - Solved knapsack using sets and mergePurge technique
    - Dynamic Programming solution
- [x] Longest Common Subsequences
    - Find the longest subsequence of two strings
- [x] NQueens
    - Place N Queens on a NxN board
    - Using a backtracking approach to start filling out from the starting square
    - Backtrack on the given condition that col != col and row != row and (abs(j - k) != abs(x[j] - i)) which makes sure that the queens can’t see each other
- [x] M Colorable graph
    - Find out the ways in which a graph can be colored using M colors without the adjecent nodes having the same color
    - Using a backtracking approach to try out all the colors on all nodes
    - Backtrack on the given condition that color appears on one of the neighbours of the node.
- [x] Hamiltonian Graph
    - Finding a path in traverses all the vertexs without repeating them
    - Using the backtracking approach we try to explore all the path and return when we can't find a vertex to traverse to other vertexs without repeating an old one
    - Gives out the correct order to traverse the graph to visit all the vertexs once
- [x] Sum of subsets
    - Finding all the subsets of a set whose sum is equal to a given value
    - Assumes that we sort the starting array
    - Using backtracking we try out all posible combinations for the subsets and quit when we - 
        - Find that the remaining values are less than than what we require
        - Current value generated + new value will tip us over the required ammount
    - Gives out the elements that make up that valid tuple
