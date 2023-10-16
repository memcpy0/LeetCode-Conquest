/*
** Problem: https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/
** Article: https://memcpy0.blog.csdn.net/article/details/133852747
** Author: memcpy0
*/
// BEST: O(n)
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int maxIdx = 0, minIdx = 0;
        for (int j = indexDifference; j < nums.size(); ++j) {
            int i = j - indexDifference;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
            else if (nums[i] < nums[minIdx]) minIdx = i;

            if (nums[maxIdx] - nums[j] >= valueDifference) return {maxIdx, j};
            if (nums[j] - nums[minIdx] >= valueDifference) return {minIdx, j};
        }
        return {-1, -1};
    }
};