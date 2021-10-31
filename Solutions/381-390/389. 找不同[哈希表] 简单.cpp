/*
** Problem: https://leetcode-cn.com/problems/find-the-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/106988949
** Author: memcpy0
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s.empty()) return t[0];
        int charset[26] = {0};
        for (const char &c : s) ++charset[c - 'a'];
        for (const char &c : t) {
            --charset[c - 'a'];
            if (charset[c - 'a'] < 0) return c;
        }
        return ' ';
    }
};