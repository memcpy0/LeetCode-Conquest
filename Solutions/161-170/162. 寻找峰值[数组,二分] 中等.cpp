/*
** Problem: https://leetcode-cn.com/problems/find-peak-element/
** Article: https://memcpy0.blog.csdn.net/article/details/120793457
** Author: memcpy0
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) r = mid; // mid落在一个山峰的右侧,mid可能是答案
            else l = mid + 1; // nums[mid]<nums[mid+1](不会取等),mid落在一个山峰的左侧且不可能是答案
        }
        return l;
    }
};