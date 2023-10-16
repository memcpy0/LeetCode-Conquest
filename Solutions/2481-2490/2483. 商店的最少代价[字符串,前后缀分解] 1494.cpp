/*
** Problem: https://leetcode.cn/problems/minimum-penalty-for-a-shop/
** Article: https://memcpy0.blog.csdn.net/article/details/133863361
** Author: memcpy0
*/
// BEST: 只用cost
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), cost = 0;
        for (int i = 0; i < n; ++i) cost += (customers[i] == 'Y');
        int minCost = cost, minIdx = 0; // 在i=0处关门的代价
        for (int i = 1; i <= n; ++i) { // 在i处关门的代价
            if (customers[i - 1] == 'N') ++cost;
            else {
                --cost;
                if (cost < minCost) {
                    minCost = cost;
                    minIdx = i;
                }
            }
        }
        return minIdx;
    }
};