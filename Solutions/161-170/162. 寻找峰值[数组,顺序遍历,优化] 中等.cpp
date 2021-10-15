/*
** Problem: https://leetcode-cn.com/problems/find-peak-element/
** Article: https://memcpy0.blog.csdn.net/article/details/120793457
** Author: memcpy0
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n - 1 && nums[i] < nums[i + 1]) ++i;
        return i;
    }
};