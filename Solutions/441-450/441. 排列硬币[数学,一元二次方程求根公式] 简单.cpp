/*
** Problem: https://leetcode-cn.com/problems/arranging-coins/
** Article: https://memcpy0.blog.csdn.net/article/details/119641437
** Author: memcpy0
*/
class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + 8ll * n)) / 2; 
    }
};