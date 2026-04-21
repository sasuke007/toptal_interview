Problem 1 — Target ~20-25 min
Find All Anagrams in a String
Given two strings s and p, return an array of all the starting indices of p's anagrams in s.
An anagram is a rearrangement of all the letters of p (using each letter exactly the number of times it appears). The output indices can be in any order.

Examples:
Input:  s = "cbaebabacd", p = "abc"
Output: [0, 6]
Explanation: 
  Substring starting at index 0: "cba" → anagram of "abc" ✓
  Substring starting at index 6: "bac" → anagram of "abc" ✓

Input:  s = "abab", p = "ab"
Output: [0, 1, 2]
Explanation:
  "ab" at index 0 ✓
  "ba" at index 1 ✓
  "ab" at index 2 ✓

Input:  s = "a", p = "aa"
Output: []
Explanation: p is longer than s, impossible.

Input:  s = "aaaaaaaaaa", p = "aaaaaaaaaaaaa"
Output: []

Input:  s = "abc", p = "abc"
Output: [0]

Constraints:

1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.


Input format for stdin:
Line 1: s
Line 2: p

Example:
cbaebabacd
abc

Expected output (space-separated or one per line):
0 6

Why this is a good 20-25 min problem:

Naive approach (sort every window) is O(n · k log k) — too slow.
Correct approach is O(n) using sliding window with character counts.
Tests: sliding window, fixed-size window, character frequency comparison.
Has a subtle optimization: instead of comparing two count arrays every step (O(26) each time), you can maintain a "matches" counter to detect anagrams in O(1) per step.

Minimum bar: O(n · 26) with array comparison at each step. Strong bar: O(n) using the matches counter.

Problem 2 — Target ~20-25 min
Rotate Image
You are given an n × n 2D matrix representing an image. Rotate the image by 90 degrees clockwise.
You must rotate the image in-place — do not allocate another 2D matrix.

Examples:
Input:  matrix = [[1,2,3],
                  [4,5,6],
                  [7,8,9]]

Output:         [[7,4,1],
                 [8,5,2],
                 [9,6,3]]

Visualization:
  Before:        After 90° clockwise:
    1 2 3              7 4 1
    4 5 6      →       8 5 2
    7 8 9              9 6 3

Input:  matrix = [[5,1,9,11],
                  [2,4,8,10],
                  [13,3,6,7],
                  [15,14,12,16]]

Output:         [[15,13,2,5],
                 [14,3,4,1],
                 [12,6,8,9],
                 [16,7,10,11]]

Input:  matrix = [[1]]
Output:         [[1]]

Input:  matrix = [[1,2],[3,4]]
Output:         [[3,1],[4,2]]

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
Must be in-place. O(1) extra space.


Input format for stdin:
Line 1: n
Next n lines: n space-separated integers per row

Example:
3
1 2 3
4 5 6
7 8 9

Expected output (n lines, n integers per line):
7 4 1
8 5 2
9 6 3