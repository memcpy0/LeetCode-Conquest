/*
** Problem: https://leetcode.cn/problems/remove-letter-to-equalize-frequency/
** Article: https://memcpy0.blog.csdn.net/article/details/130438156
** Author: memcpy0
*/
class Solution {
public:
    bool equalFrequency(string word) {
        int cnt[26]{};
        for(char c : word) ++cnt[c-'a'];
        int maxCnt = 0, minCnt = word.size();
        int allCntCnt = 0; // 出现的字符种数
        for(int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                ++allCntCnt;
                maxCnt=max(cnt[i], maxCnt);
                minCnt=min(cnt[i], minCnt);
            }
        }
        // (出现次数只有一种): 所有字符出现次数为1或只有一种字符的情况
        if (allCntCnt == 1 || maxCnt == 1) return true;
        int maxCntCnt = 0; // 出现次数最多的字符种数
        for(int i = 0; i < 26; ++i)
            if (cnt[i] == maxCnt)
                ++maxCntCnt;
        // 出现次数最大的字符和出现次数最少的字符仅相差1次, 且只有一种出现次数最大的字符
        // 或者出现次数最少的字符次数为1次, 且其它字符出现次数均相同
        return (maxCnt - minCnt == 1 && maxCntCnt == 1) || 
            (minCnt == 1 && maxCntCnt == allCntCnt - 1);
    }
};

// class Solution {
//     bool isSame(unordered_map<char, int> &cnt) {
//         int c0 = cnt.begin()->second;
//         for (auto &[_, c] : cnt) 
//             if (c != c0) return false;
//         return true;
//     }
// public:
//     bool equalFrequency(string word) { 
//         for (int i = 0, n = word.size(); i < n; ++i) { // 枚举删除的字符
//             unordered_map<char, int> cnt;
//             for (int j = 0; j < n; ++j)
//                 if (j != i) ++cnt[word[j]]; // 统计出现次数
//             if (isSame(cnt)) // 出现次数都一样
//                 return true;
//         } 
//         return false;
//     }
// }; 

// class Solution { 
// public:
//     bool equalFrequency(string word) { 
//         unordered_map<char, int> rec;
//         for (char c : word) ++rec[c];
//         vector<int> cnt;
//         for (auto &[_, c] : rec) cnt.push_back(c);
//         sort(cnt.begin(), cnt.end()); // 出现次数从小到大排序
//         // 只有1种字符 or 去掉次数最少的 or 出掉次数最多的
//         return cnt.size() == 1 || 
//             cnt[0] == 1 && equal(cnt.begin() + 2, cnt.end(), cnt.begin() + 1) ||
//             cnt.back() == cnt[cnt.size() - 2] + 1 && equal(cnt.begin() + 1, cnt.end() - 1, cnt.begin());
//     }
// }; 