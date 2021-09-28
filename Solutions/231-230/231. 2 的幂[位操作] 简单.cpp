/*
** Problem: https://leetcode-cn.com/problems/power-of-two/
** Article: https://memcpy0.blog.csdn.net/article/details/120535883
** Author: memcpy0
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {  
        return n > 0 && !(n & (n - 1));
    }
};