/*
** Problem: https://leetcode-cn.com/problems/number-complement/
** Article: https://memcpy0.blog.csdn.net/article/details/108866890
** Author: memcpy0
*/
class Solution {
public:
    int findComplement(int num) {
        int x = 0;
        for (int i = num; i; i -= i & -i) x = i;
        return num ^ (((unsigned)x << 1) - 1);
    }
};