/*
** Problem: https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
** Article: https://memcpy0.blog.csdn.net/article/details/108710821
** Author: memcpy0
*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; j += 2) { //遍历奇数长度
                int sum = 0;
                for (int k = i; k <= j; ++k) sum += arr[k];
                ans += sum;
            }
        }
        return ans;
    }   
};