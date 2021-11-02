/*
** Problem: https://leetcode-cn.com/problems/number-complement/
** Article: https://memcpy0.blog.csdn.net/article/details/108866890
** Author: memcpy0
*/
class Solution {
public:
    int findComplement(int num) {
        int n = num;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16; 
        return n ^ num;
    }
};