/*
** Problem: https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/133904630
** Author: memcpy0
*/
class Solution {
public:
    int differenceOfSums(int n, int m) {
        return n * (n + 1) / 2 - n / m * (n / m + 1) * m;
    }
};