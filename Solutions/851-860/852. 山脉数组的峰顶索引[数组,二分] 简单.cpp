/*
** Problem: https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
** Article: https://memcpy0.blog.csdn.net/article/details/109695803
** Author: memcpy0
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2; // 题解下标的范围为[1,n-2]
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            else if (arr[mid] > arr[mid - 1]) l = mid + 1; // mid落在山脉左侧
            else r = mid - 1; // mid落在山脉右侧 
        }
        return -1;
    }
};