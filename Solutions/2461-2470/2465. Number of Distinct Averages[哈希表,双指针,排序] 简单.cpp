/*
** Problem: https://leetcode.cn/problems/number-of-distinct-averages/
** Article: https://memcpy0.blog.csdn.net/article/details/131046325
** Author: memcpy0
*/
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> rec;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) 
            rec.insert(nums[i] + nums[j]);
        return rec.size();
    }
};