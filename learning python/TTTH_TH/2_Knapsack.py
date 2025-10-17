"""
There are n orders 1, 2, . . ., n in which r[i] is the amount of goods of order i (i = 1, 2, . . ., n). The revenue of serving order i is P*r[i] (with P is a constant: price of deliverying 1 unit of good) There are m trucks 1, 2, . . ., m in which each truck j (j = 1, 2, . . ., m) has:
capacity q[j]
cost c[j]
Find the way to load orders into trucks such that:
Each order is assigned to at most on truck (an order can be unserved)
Total amount of goods loaded into a truck cannot exceed its capacity
Total benifits (total revenue - total cost) is maximal
A solution is represented by an array s[1], s[2],  . . ., s[n] in which s[i] is the index (1, . . .,  m) of the truck serving the order i. If the order i is not served, then s[i] = -1
Input
Line 1: 3 positive integers m, n, P
Line 2: r[1], r[2], . . ., r[n]
Line 2+j (j = 1,. . ., m): contains q[j], and c[j]


Output
Line 1: contains n
Line 2: contains s[1], s[2],  . . ., s[n]


Example
Input
3 6 20
4 2 5 7 3 1
10 8
12 9
15 10
Output
6
1  1  2  2  1  -1
"""