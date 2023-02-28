/*
** Problem: https://leetcode.cn/problems/maximum-score-words-formed-by-letters/
** Article: https://memcpy0.blog.csdn.net/article/details/129273445
** Author: memcpy0
*/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), ans = 0, tot = 1 << n;
        vector<int> count(26);
        for (auto c : letters) ++count[c - 'a'];
        for (int s = 1; s < tot; ++s) {
            vector<int> wordCount(26); // 统计子集s所有单词的字母数目
            for (int k = 0; k < n; ++k) {
                if ((s & (1 << k)) == 0) continue; // words[k]不在子集s中
                for (auto c : words[k]) ++wordCount[c - 'a'];
            }
            bool ok = true; // 判断子集s是否valid
            int sum = 0; // 保存子集s的得分
            for (int i = 0; i < 26; ++i) {
                sum += score[i] * wordCount[i];
                ok = ok && (wordCount[i] <= count[i]);
            }
            if (ok) ans = max(ans, sum);
        }
        return ans;
    }
};