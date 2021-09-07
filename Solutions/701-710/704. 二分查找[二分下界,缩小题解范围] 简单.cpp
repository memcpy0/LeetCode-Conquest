/*
** Problem: https://leetcode-cn.com/problems/binary-search/
** Article: https://memcpy0.blog.csdn.net/article/details/108890175
** Author: memcpy0
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + hi >> 1;
            if (nums[mid] >= target) hi = mid; 
            else lo = mid + 1;  
        }
        return nums[lo] != target ? -1 : lo;
    }
};