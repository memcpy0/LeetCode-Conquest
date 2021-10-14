/*
** Problem: https://leetcode-cn.com/problems/arranging-coins/
** Article: https://memcpy0.blog.csdn.net/article/details/119641437
** Author: memcpy0
*/
class Solution {
public:
    int arrangeCoins(int n) { 
        int level = 1;
        while (n >= level) n -= (level++); 
        return level - 1;
    }
};