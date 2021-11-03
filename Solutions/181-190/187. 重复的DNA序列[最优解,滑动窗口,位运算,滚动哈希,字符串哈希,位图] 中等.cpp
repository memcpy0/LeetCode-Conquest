/*
** Problem: https://leetcode-cn.com/problems/repeated-dna-sequences/
** Article: https://memcpy0.blog.csdn.net/article/details/120662605
** Author: memcpy0
*/
class Solution {
private: // 对应二进制数{00,01,10,11},那么长度为10的子串只要20位即可表示
    unordered_map<char, int> rec = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        vector<string> ans;
        bitset<1 << 20> s1, s2; // 所有可能子串的二进制数值在0到(1 << 20 - 1)之间
        int n = s.size(), val = 0, mask = (1 << 20) - 1; // mask为二进制数的20个1
        // 使用滑动窗口+滚动计算,先把前10个字母的二进制数计算出来
        for (int i = 0; i < 10; ++i) val = (val << 2) | rec[s[i]];
        s1.set(val); // 置位,表示前10个字母组成的子串已经出现
        for (int i = 10; i < n; ++i) {
            val = ((val << 2) & mask) | rec[s[i]]; // 去掉左移的一个字符,再加上一个新字符
            if (s2.test(val)) continue; // 出现过两次则跳过
            if (s1.test(val)) { // 出现了一次
                ans.push_back(s.substr(i - 9, 10));
                s2.set(val); // 表示出现了第二次
            } else s1.set(val); // 表示出现了一次
        }
        return ans;
    }
};