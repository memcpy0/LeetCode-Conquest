/*
** Problem: https://leetcode-cn.com/problems/valid-perfect-square/
** Article: https://memcpy0.blog.csdn.net/article/details/109349499
** Author: memcpy0
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = 1;
        while (num >= x) {
            num -= x;
            x += 2;
        }
        return !num;
    }
};