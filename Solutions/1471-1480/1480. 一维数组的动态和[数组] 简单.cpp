/*
** Problem: https://leetcode-cn.com/problems/running-sum-of-1d-array/
** Article: https://memcpy0.blog.csdn.net/article/details/109634506
** Author: memcpy0
*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for (const int &v : nums) {
            sum += v;
            ans.push_back(sum);
        }
        return ans;
    }
};