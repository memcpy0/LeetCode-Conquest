/*
** Problem: https://leetcode-cn.com/problems/count-number-of-pairs-with-absolute-difference-k/
** Article: https://memcpy0.blog.csdn.net/article/details/120475001
** Author: memcpy0
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; ++i)
            for (int j = i + 1; j < n; ++j) 
                if (abs(nums[i] - nums[j]) == k)
                    ++ans;
        return ans;
    }
};