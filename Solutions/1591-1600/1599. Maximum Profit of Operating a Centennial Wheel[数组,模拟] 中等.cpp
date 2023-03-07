/*
** Problem: https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel
** Article: https://memcpy0.blog.csdn.net/article/details/129375786
** Author: memcpy0
*/
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0, maxProfit = 0, maxTimes = -1, remains = 0; 
        for (int i = 0, n = customers.size(); i < n || remains; ++i) {
            if (i < n) remains += customers[i];
            int t = (remains > 4) ? 4 : remains;
            remains -= t;
            profit += t * boardingCost - runningCost;
            if (profit > maxProfit) {
                maxProfit = profit;
                maxTimes = i + 1; // 注意是i+1
            }
        }
        return maxTimes;
    }
};