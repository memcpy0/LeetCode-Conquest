/*
** Problem: https://leetcode-cn.com/problems/count-number-of-pairs-with-absolute-difference-k/
** Article: https://memcpy0.blog.csdn.net/article/details/120475001
** Author: memcpy0
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt[102] = {0}, ans = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] - k >= 0) ans += cnt[nums[i] - k];
            if (nums[i] + k <= 100) ans += cnt[nums[i] + k];
            ++cnt[nums[i]]; 
        }
        return ans;
    }
};