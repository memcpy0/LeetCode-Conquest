/*
** Problem: https://leetcode.cn/problems/check-distances-between-same-letters/
** Article: https://memcpy0.blog.csdn.net/article/details/130037349
** Author: memcpy0
*/
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int d[26]; memset(d, -1, sizeof(d));
        for (int i = 0, n = s.size(); i < n; ++i) {
            int v = s[i] - 'a';
            if (d[v] == -1) d[v] = i;
            else if (i - d[v] - 1 != distance[v]) return false;
        }
        return true;
    }
};