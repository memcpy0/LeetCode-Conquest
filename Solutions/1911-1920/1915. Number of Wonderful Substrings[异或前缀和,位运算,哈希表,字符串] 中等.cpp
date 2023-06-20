/*
** Problem: https://leetcode.cn/problems/number-of-wonderful-substrings/
** Article: https://memcpy0.blog.csdn.net/article/details/131313178
** Author: memcpy0
*/
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size(), xor_sum = 0;
        long long ans = 0;
        int cnt[1024] = {0};
        cnt[0] = 1; // 初始前缀和为0,需将其计入出现次数
        for (char c : word) {
            xor_sum ^= (1 << (c - 'a')); // 计算当前前缀和
            ans += cnt[xor_sum]; // 所有字母均出现偶数次
            for (int j = 0; j <= 9; ++j) // 枚举其中一个字母出现奇数次
                ans += cnt[xor_sum ^ (1 << j)]; // 反转该字母的出现次数的奇偶性
            ++cnt[xor_sum]; // 更新前缀和出现次数
        }
        return ans;
    }
};