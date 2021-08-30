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
        vector<int> presum(n + 1);
        for (int i = 0; i < n; ++i) presum[i + 1] = presum[i] + arr[i];
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; j += 2) //遍历奇数长度
                ans += presum[j + 1] - presum[i];
        return ans;
    }   
};