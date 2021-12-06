/*
** Problem: https://leetcode-cn.com/problems/truncate-sentence/
** Article: https://memcpy0.blog.csdn.net/article/details/121747086
** Author: memcpy0
*/
class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == ' ' && --k == 0) break;
            ++i;
        }
        return s.substr(0, i);
    }
};