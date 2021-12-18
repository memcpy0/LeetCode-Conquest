/*
** Problem: https://leetcode-cn.com/problems/water-bottles/
** Article: https://memcpy0.blog.csdn.net/article/details/122007151
** Author: memcpy0
*/
class Solution {
public:
    int numWaterBottles(int n, int m) {
        return n % (m - 1) == 0 ? (n + n / (m - 1) - 1) : (n + n / (m - 1));
    }
};