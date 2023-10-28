/*
** Problem: https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/
** Article: https://memcpy0.blog.csdn.net/article/details/134089821
** Author: memcpy0
*/
// 数学
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        return (mx + mx + k - 1) * k / 2;
    }
};