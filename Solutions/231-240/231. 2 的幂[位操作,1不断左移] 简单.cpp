/*
** Problem: https://leetcode-cn.com/problems/power-of-two/
** Article: https://memcpy0.blog.csdn.net/article/details/120535883
** Author: memcpy0
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        uint32_t x = 1;
        while (x < n) x <<= 1;
        return x == n;
    }
};