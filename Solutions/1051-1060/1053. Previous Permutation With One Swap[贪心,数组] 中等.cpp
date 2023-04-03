/*
** Problem: https://leetcode.cn/problems/previous-permutation-with-one-swap/
** Article: https://memcpy0.blog.csdn.net/article/details/129942393
** Author: memcpy0
*/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size(), i;
        for (i = n - 2; i >= 0 && arr[i] <= arr[i + 1]; --i);
        if (i == -1) return arr;
        int j;
        for (j = n - 1; arr[j] >= arr[i] || arr[j] == arr[j - 1]; --j);
        swap(arr[i], arr[j]);
        return arr;
    }
};