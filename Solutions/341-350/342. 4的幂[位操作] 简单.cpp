/*
** Problem: https://leetcode-cn.com/problems/power-of-four/
** Article: https://memcpy0.blog.csdn.net/article/details/117408777
** Author: memcpy0
*/
class Solution {
public:
    bool isPowerOfFour(int n) { 
        //0b0101 0101 0101 0101 0101 0101 0101 0101
        return n > 0 && !(n & (n - 1)) && (n & 0x55555555);
    }
};