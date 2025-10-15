/*
Monocarp has a string 𝑠 of length 𝑛, consisting of the letters 'a' and 'b'. He wants to remove some (possibly zero) number of consecutive letters from his string in such a way that the number of letters 'a' and 'b' in the resulting string becomes equal. Monocarp can start removing letters from any position in the string 𝑠.
Monocarp really likes his string 𝑠, so he wants to remove as few consecutive letters from it as possible.
Your task is to determine the minimum number of consecutive letters from the string 𝑠 that need to be removed so that the number of letters 'a' and 'b' in the resulting string becomes equal. If it is necessary to remove all letters from the string 𝑠 (i.e., make it empty), report this.
Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases.
Each test case consists of two lines:
the first line contains one integer 𝑛 (2≤𝑛≤2⋅105) — the number of characters in the string 𝑠;
the second line contains the string 𝑠 of length 𝑛, consisting of the letters 'a' and/or 'b'.
Additional constraint on the input: the sum of values of 𝑛 over all test cases does not exceed 2⋅105.
Output
For each test case, print the answer as follows:
If in order to make the number of letters 'a' and 'b' equal, it is necessary to remove all letters from the string 𝑠, output −1.
Otherwise, output the minimum number of consecutive letters that Monocarp needs to remove from his string 𝑠 so that the number of letters 'a' and 'b' becomes equal.
Example
Input
Copy
5
5
bbbab
6
bbaaba
4
aaaa
12
aabbaaabbaab
5
aabaa
Output
Copy
3
0
-1
2
-1
Note
In the first example, Monocarp needs to remove the first three letters from his string. After that, his string will become "ab". In this string, there is one letter 'a' and one letter 'b'.
In the second example, the given string has three letters 'a' and three letters 'b', so nothing needs to be removed.
In the third example, all letters of the string need to be removed, as there are no letters 'b', so −1 should be printed.
In the fourth example, Monocarp can, for example, remove the fifth and sixth letters from his string. Then his string will become "aabbabbaab". In this string, there are five letters 'a' and five letters 'b'.
In the fifth example, all letters of the string need to be removed to make the number of letters 'a' and 'b' equal, so −1 should be printed.
*/