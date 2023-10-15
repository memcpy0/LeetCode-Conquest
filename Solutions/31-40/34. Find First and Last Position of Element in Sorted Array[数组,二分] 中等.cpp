/*
** Problem: https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
** Article: https://memcpy0.blog.csdn.net/article/details/108372747
** Author: memcpy0
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (left > right) return {-1, -1};
        return vector<int>{left, right};
    }
};

class Solution {
private: 
    //找到第一个>=v的元素的位置
    int lowerBound(vector<int>& A, int x, int y, int v) {
        while (x < y) {
            int m = x + (y - x) / 2;
            if (A[m] >= v) y = m;
            else x = m + 1;
        }
        return x;
    }
    //找到第一个>v的元素的位置
    int upperBound(vector<int>& A, int x, int y, int v) {
        while (x < y) {
            int m = x + (y - x) / 2;
            if (A[m] > v) y = m;
            else x = m + 1;
        }
        return x;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1}; //特判空
        int n = nums.size();
        int first = lowerBound(nums, 0, n, target); //第一个<=
        if (first >= n || nums[first] != target) return vector<int>{-1, -1}; //特判不存在
        int last = upperBound(nums, 0, n, target); //第一个< 
        return vector<int>{first, last - 1}; 
    }
};