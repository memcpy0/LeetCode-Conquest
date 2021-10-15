/*
** Problem: https://leetcode-cn.com/problems/B1IidL/
** Article: https://memcpy0.blog.csdn.net/article/details/120792269
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