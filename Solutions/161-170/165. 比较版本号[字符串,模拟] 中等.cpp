/*
** Problem: https://leetcode-cn.com/problems/compare-version-numbers/
** Article: https://memcpy0.blog.csdn.net/article/details/120057739
** Author: memcpy0
*/
class Solution {
private:
    vector<string> split(const string& s, char delim = ' ') {
        vector<string> tokens;
        if (s.empty()) return tokens;
        size_t beginPos = s.find_first_not_of(delim);
        size_t endPos = s.find_first_of(delim, beginPos);
        while (beginPos != string::npos) {
            tokens.push_back(s.substr(beginPos, endPos));
            beginPos = s.find_first_not_of(delim, endPos);
            endPos = s.find_first_of(delim, beginPos);
        }
        return tokens;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> &&v1 = split(version1, '.'), &&v2 = split(version2, '.');
        for (int i = 0, j = 0, n = v1.size(), m = v2.size(); i < n || j < m; ++i, ++j) {
            int revis1 = i < n ? stoi(v1[i]) : 0;
            int revis2 = j < m ? stoi(v2[j]) : 0;
            if (revis1 != revis2) return revis1 < revis2 ? -1 : 1;
        }
        return 0;
    }
};