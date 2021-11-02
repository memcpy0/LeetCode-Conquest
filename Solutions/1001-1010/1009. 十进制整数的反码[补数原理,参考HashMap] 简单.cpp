/*
** Problem: https://leetcode-cn.com/problems/complement-of-base-10-integer/
** Article: https://memcpy0.blog.csdn.net/article/details/108867646
** Author: memcpy0
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int num = n;
        num |= num >> 1;
        num |= num >> 2;
        num |= num >> 4;
        num |= num >> 8;
        num |= num >> 16;
        return n ^ num;
    }
};