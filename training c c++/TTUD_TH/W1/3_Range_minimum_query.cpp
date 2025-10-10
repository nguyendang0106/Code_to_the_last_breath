/*
Mô tả
Given a sequence of n integers a0,. . .,an-1. We denote rmq(i,j) the minimum element of the sequence ai, ai+1, . . .,aj. Given m pairs (i1, j1),. . .,(im, jm), compute the sum Q = rmq(i1,j1) + . . . + rmq(im, jm)
Input
Line 1: n (1 <=  n <= 106)
Line 2: a0, . . . ,an-1 ( 1  <=  ai <= 106)
line 3: m (1  <= m <= 106)
Line k+3 (k=1, . . ., m): ik, jk (0  <=  ik < jk < n)
Output
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6


*/