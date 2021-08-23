/*
** Problem: https://leetcode-cn.com/problems/get-maximum-in-generated-array/
** Article: https://memcpy0.blog.csdn.net/article/details/119879925
** Author: memcpy0
*/
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) return n;
        int arr[101] = {0, 1}, ans = 1;
        for (int i = 2; i <= n; ++i) {
            arr[i] = (i & 1) ? arr[i >> 1] + arr[(i >> 1) + 1] : arr[i >> 1];
            ans = max(arr[i], ans);
        }
        return ans;  
    }
};