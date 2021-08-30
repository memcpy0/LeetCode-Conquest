/*
** Problem: https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
** Article: https://memcpy0.blog.csdn.net/article/details/108710821
** Author: memcpy0
*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;  
        for (int i = 0, n = arr.size(); i < n; ++i) {
            int l1 = (i + 1) / 2, r1 = (n - i) / 2; //奇数个数
            int l2 = i / 2 + 1, r2 = (n - i - 1) / 2 + 1; //偶数个数
            ans += arr[i] * (l1 * r1 + l2 * r2);
        }
        return ans;
    }   
};