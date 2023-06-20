/*
** Problem: https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/
** Article: https://memcpy0.blog.csdn.net/article/details/131307387
** Author: memcpy0
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size(), xor_sum = 0, ans = 0;
        vector<int> pos(1 << 5, -1);
        pos[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') xor_sum ^= 1;
            else if (s[i] == 'e') xor_sum ^= 1 << 1;
            else if (s[i] == 'i') xor_sum ^= 1 << 2;
            else if (s[i] == 'o') xor_sum ^= 1 << 3;
            else if (s[i] == 'u') xor_sum ^= 1 << 4;
            if (~pos[xor_sum]) ans = max(i + 1 - pos[xor_sum], ans);
            else pos[xor_sum] = i + 1;
        }
        return ans;
    }
};