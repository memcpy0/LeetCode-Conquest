/*
** Problem: https://leetcode-cn.com/problems/repeated-dna-sequences/
** Article: https://memcpy0.blog.csdn.net/article/details/120662605
** Author: memcpy0
*/
class Solution {
private:
    static const int maxn = 1e5 + 10;
    unsigned P = 131313;
    unsigned hash[maxn] = {0}, p[maxn] = {1};
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            hash[i] = hash[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }
        unordered_map<unsigned, int> rec;
        for (int i = 1; i <= n - 10 + 1; ++i) {
            int j = i + 10 - 1; // [i,j]标志这一长度为10的子串区间
            unsigned seqHash = hash[j] - hash[i - 1] * p[j - i + 1]; // p[10]
            int &cnt = rec[seqHash];
            if (cnt == 1) ans.push_back(s.substr(i - 1, 10));
            ++cnt;
        }
        return ans;
    }
};