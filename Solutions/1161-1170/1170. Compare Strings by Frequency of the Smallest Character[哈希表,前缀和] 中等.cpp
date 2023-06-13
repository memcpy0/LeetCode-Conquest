/*
** Problem: https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character
** Article: https://memcpy0.blog.csdn.net/article/details/131198230
** Author: memcpy0
*/
class Solution {
private:
    int f(string& s) { 
        int cnt = 0;
        char c = 'z';
        for (char ch : s) {
            if (ch < c) {
                c = ch;
                cnt = 1;
            } else if (ch == c) ++cnt;
        }
        return cnt;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        int cnt[12]{0};
        for (auto &s : words) ++cnt[f(s)]; 
        for (int i = 9; i >= 1; --i) cnt[i] += cnt[i + 1]; // 后缀和
        vector<int> ans;
        for (auto &s : queries)
            ans.push_back(cnt[f(s) + 1]);
        return ans;
    }
};