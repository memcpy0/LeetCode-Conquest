/*
** Problem: https://leetcode.cn/problems/smallest-even-multiple/
** Article: https://memcpy0.blog.csdn.net/article/details/130278738
** Author: memcpy0
*/
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n & 1) ? 2 * n : n;
    }
};
/*
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return 2 / __gcd(2, n) * n;
    }
};
*/