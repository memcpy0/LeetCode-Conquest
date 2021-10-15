/*
** Problem: https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
** Article: https://memcpy0.blog.csdn.net/article/details/109695803
** Author: memcpy0
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 1, n = arr.size(); i < n - 1; ++i)
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
        return -1;
    }
};