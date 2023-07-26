/*
** Problem: https://leetcode.cn/problems/maximum-sum-circular-subarray/
** Article: https://memcpy0.blog.csdn.net/article/details/131948302
** Author: memcpy0
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            total += num; 
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};