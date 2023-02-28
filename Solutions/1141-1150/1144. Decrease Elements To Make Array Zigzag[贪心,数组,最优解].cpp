/*
** Problem: https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/
** Article: https://memcpy0.blog.csdn.net/article/details/129273456
** Author: memcpy0
*/
class Solution {
public: 
    int movesToMakeZigzag(vector<int>& nums) {
        auto helper = [&](int start) -> int {
            int moves = 0;
            for (int i = start, n = nums.size(); i < n; i += 2) {
                int minVal = INT_MAX;
                if (i - 1 >= 0) minVal = min(minVal, nums[i - 1]);
                if (i + 1 < n) minVal = min(minVal, nums[i + 1]);
                if (minVal <= nums[i]) moves += nums[i] - minVal + 1; // 记录改变值
            }
            return moves;
        };
        return min(helper(1), helper(0));
    }
};