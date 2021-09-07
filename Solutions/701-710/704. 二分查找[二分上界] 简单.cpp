/*
** Problem: https://leetcode-cn.com/problems/binary-search/
** Article: https://memcpy0.blog.csdn.net/article/details/108890175
** Author: memcpy0
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1; //题解范围到[0,n),但是插入范围为[0,n],插入时特判结果下标为0的位置
        while (lo < hi) {
            int mid = lo + hi + 1 >> 1; //注意+1
            if (nums[mid] <= target) lo = mid; //找到最后一个<=target的元素位置
            else hi = mid - 1;
        }
        return nums[lo] == target ? lo : -1;
    }
};