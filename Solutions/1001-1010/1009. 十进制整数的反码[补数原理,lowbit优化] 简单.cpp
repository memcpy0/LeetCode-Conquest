/*
** Problem: https://leetcode-cn.com/problems/complement-of-base-10-integer/
** Article: https://memcpy0.blog.csdn.net/article/details/108867646
** Author: memcpy0
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int x = 0;
        for (int i = n; i; i -= i & -i) x = i;
        return n ^ (((unsigned)x << 1) - 1);
    }
};