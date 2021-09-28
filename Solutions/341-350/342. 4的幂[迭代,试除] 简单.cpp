/*
** Problem: https://leetcode-cn.com/problems/power-of-four/
** Article: https://memcpy0.blog.csdn.net/article/details/117408777
** Author: memcpy0
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
};