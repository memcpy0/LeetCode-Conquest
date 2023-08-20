/*
** Problem: https://leetcode.cn/problems/find-and-replace-in-string/
** Article: https://memcpy0.blog.csdn.net/article/details/132394155
** Author: memcpy0
*/
// BEST: 字符串+哈希表+模拟
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans;
        int k = indices.size(), n = s.size();
        int matchIndex[n];
        memset(matchIndex, -1, sizeof(matchIndex));

        for (int i = 0; i < k; ++i) {
            int sn = sources[i].size();
            bool isMatch = true;
            for (int j = indices[i]; j < indices[i] + sn; ++j) { // j为原串中的下标
                if (sources[i][j - indices[i]] != s[j]) { // 某个字符不同
                    isMatch = false;
                    break;
                }
            } // 如果子串出现在原串的indices[i]处，则记录要用来替换的新串的下标
            if (isMatch) matchIndex[indices[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (matchIndex[i] != -1) { // 要进行替换
                int index = matchIndex[i];
                ans += targets[index];
                i = indices[index] + sources[index].size() - 1; // i要跳转到原串后面
            } else ans.push_back(s[i]);
        }
        return ans;
    }
};