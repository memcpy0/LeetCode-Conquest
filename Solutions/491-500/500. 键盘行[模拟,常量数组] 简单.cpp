/*
** Problem: https://leetcode-cn.com/problems/keyboard-row/
** Article: https://memcpy0.blog.csdn.net/article/details/108820492
** Author: memcpy0
*/
static const int pos[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for (const string &word : words) {
            bool flag = true;
            int p1 = pos[tolower(word[0]) - 'a'];
            for (int i = 1, n = word.size(); i < n; ++i) {
                int p2 = pos[tolower(word[i]) - 'a'];
                if (p1 != p2) {
                    flag = false;
                    break;
                }
                p1 = p2;
            }
            if (flag) ans.push_back(word);
        }
        return ans;
    }
};