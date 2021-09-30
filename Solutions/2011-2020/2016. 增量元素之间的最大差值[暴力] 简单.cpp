/*
** Problem: https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/
** Article: https://memcpy0.blog.csdn.net/article/details/120559756
** Author: memcpy0
*/
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        for (int i = 0, n = nums.size(); i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (nums[i] < nums[j])
                    ans = max(ans, nums[j] - nums[i]);
        return ans;
    }
};