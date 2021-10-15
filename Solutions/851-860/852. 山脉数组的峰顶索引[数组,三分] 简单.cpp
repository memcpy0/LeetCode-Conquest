/*
** Problem: https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
** Article: https://memcpy0.blog.csdn.net/article/details/109695803
** Author: memcpy0
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2; // 题解下标的范围为[1,n-2]
        while (l < r) {
            int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
            if (arr[lmid] > arr[rmid]) r = rmid - 1;
            else l = lmid + 1;
        }
        return r;
    }
};