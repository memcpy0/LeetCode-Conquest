/*
** Problem: https://leetcode-cn.com/problems/sqrtx/
** Article: https://memcpy0.blog.csdn.net/article/details/121135932
** Author: memcpy0
*/
class Solution {
    public int mySqrt(int x) {
        if (x <= 1) return x;
        int xi = x / 2;
        while (xi > x / xi)
            xi = (xi + x / xi) / 2;
        return xi;
    }
}