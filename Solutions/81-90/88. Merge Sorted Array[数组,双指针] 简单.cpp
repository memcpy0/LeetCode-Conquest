/*
** Problem: https://leetcode.cn/problems/merge-sorted-array
** Article: https://memcpy0.blog.csdn.net/article/details/132392280
** Author: memcpy0
*/
// BEST: 逆向双指针归并
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) cur = nums2[p2--];
            else if (p2 == -1) cur = nums1[p1--];
            else if (nums1[p1] > nums2[p2]) cur = nums1[p1--];
            else cur = nums2[p2--];
            nums1[tail--] = cur;
        }
    }
};