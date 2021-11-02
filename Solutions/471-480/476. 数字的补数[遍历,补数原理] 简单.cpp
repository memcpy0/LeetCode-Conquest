/*
** Problem: https://leetcode-cn.com/problems/number-complement/
** Article: https://memcpy0.blog.csdn.net/article/details/108866890
** Author: memcpy0
*/
class Solution {
public:
    int findComplement(int num) {
        for (int k = 0; k < 32; ++k) {
            unsigned int n = 1 << k;
            if (n > num) return n - 1 - num;
        }
        return 0;
    }
};