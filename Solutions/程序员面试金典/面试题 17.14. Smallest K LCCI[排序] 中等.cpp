/*
** Problem: https://leetcode-cn.com/problems/smallest-k-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/120108542
** Author: memcpy0
*/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};