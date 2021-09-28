/*
** Problem: https://leetcode-cn.com/problems/power-of-four/
** Article: https://memcpy0.blog.csdn.net/article/details/117408777
** Author: memcpy0
*/
class Solution {
public:
    bool isPowerOfFour(int n) { 
        long long x = 1;
        while (x < n) x <<= 2;
        return x == n; 
    }
};