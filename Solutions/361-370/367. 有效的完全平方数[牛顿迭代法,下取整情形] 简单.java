/*
** Problem: https://leetcode-cn.com/problems/valid-perfect-square/
** Article: https://memcpy0.blog.csdn.net/article/details/109349499
** Author: memcpy0
*/
class Solution {
    public boolean isPerfectSquare(int num) {
        if (num <= 1) return true;
        int xi = num / 2;
        while (xi > num / xi) xi = (xi + num / xi) / 2;
        return xi * xi == num;
    }
}