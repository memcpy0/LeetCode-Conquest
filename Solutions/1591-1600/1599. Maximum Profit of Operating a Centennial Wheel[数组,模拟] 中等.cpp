/*
** Problem: https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel
** Article: https://memcpy0.blog.csdn.net/article/details/129375786
** Author: memcpy0
*/
// cpp
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0, maxProfit = 0, maxTimes = -1, remains = 0; 
        for (int i = 0, n = customers.size(); i < n || remains; ++i) {
            if (i < n) remains += customers[i];
            int t = min(remains, 4);
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

// java
class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        int profit = 0, maxProfit = 0, maxTimes = -1, remains = 0; 
        for (int i = 0, n = customers.length; i < n || remains > 0; ++i) {
            if (i < n) remains += customers[i];
            int t = Math.min(remains, 4);
            remains -= t;
            profit += t * boardingCost - runningCost;
            if (profit > maxProfit) {
                maxProfit = profit;
                maxTimes = i + 1; // 注意是i+1
            }
        }
        return maxTimes;
    }
}

// python
class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        maxProfit = profit = 0
        maxTimes = -1
        remains = 0
        i, n = 0, len(customers)
        while i < n or remains:
            remains += customers[i] if i < n else 0
            t = min(remains, 4)
            remains -= t
            profit += t * boardingCost - runningCost
            if profit > maxProfit:
                maxProfit = profit
                maxTimes = i + 1
            i += 1
        return maxTimes

// go
func minOperationsMaxProfit(customers []int, boardingCost int, runningCost int) int {
    profit, maxProfit := 0, 0
    maxTimes := -1
    remains := 0
    n := len(customers)
    for i := 0; i < n || remains > 0; i++ {
        if i < n {
            remains += customers[i]
        }
        t := 4
        if remains < 4 {
            t = remains
        }
        remains -= t
        profit += t * boardingCost - runningCost
        if profit > maxProfit {
            maxProfit = profit
            maxTimes = i + 1
        }
    }
    return maxTimes
}