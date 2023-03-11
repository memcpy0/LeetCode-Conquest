/*
** Problem: https://leetcode-cn.com/problems/find-longest-subarray-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/112252758
** Author: memcpy0
*/
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size(), left = 0, right = 0;
        int partial_sum = n, rec[n + n + 1];
        memset(rec, -1, sizeof(rec));
        rec[partial_sum] = 0; // partial_sum[0]=0
        for (int i = 1; i <= n; ++i) {
            partial_sum += ((array[i - 1][0] >> 6) & 1) * 2 - 1;
            int j = rec[partial_sum];
            if (j < 0) rec[partial_sum] = i;
            else if (i - j > right - left) left = j, right = i; 
        }
        return {array.begin() + left, array.begin() + right};  
    }
};