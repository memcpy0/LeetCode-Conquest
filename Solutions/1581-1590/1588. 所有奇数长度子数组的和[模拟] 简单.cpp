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
            int sum = arr[i];
            ans += sum;
            for (int j = i + 2; j < n; j += 2) { //遍历奇数长度
                sum += arr[j - 1] + arr[j];
                ans += sum;
            }
        }
        return ans;
    }   
};