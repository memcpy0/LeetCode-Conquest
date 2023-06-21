/*
** Problem: https://leetcode.cn/problems/find-longest-awesome-substring/
** Article: https://memcpy0.blog.csdn.net/article/details/131316399
** Author: memcpy0
*/
class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size(), xor_sum = 0, ans = 0;
        int rec[1024];
        memset(rec, -1, sizeof(rec)); // 空前缀对应键值对(0,-1)
        for (int i = 0; i < n; ++i) {
            xor_sum ^= 1 << (s[i] - '0'); // 特判异或前缀和为0的情况
            if (xor_sum == 0 || ~rec[xor_sum]) ans = max(ans, i - rec[xor_sum]);
            else rec[xor_sum] = i;
            for (int j = 0; j < 10; ++j) {
                int t = xor_sum ^ (1 << j);
                if (t == 0 || ~rec[t]) // 特判翻转后为0的情况
                    ans = max(ans, i - rec[t]);
            }
        }
        return ans;
    }
};