/*
** Problem: https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted
** Article: https://memcpy0.blog.csdn.net/article/details/131630013
** Author: memcpy0
*/
// BEST: 双指针
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size(), i = 0, j = n - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) return {i + 1, j + 1};
            else if (sum < target) ++i;
            else --j;
        }
        return {};
    }
};