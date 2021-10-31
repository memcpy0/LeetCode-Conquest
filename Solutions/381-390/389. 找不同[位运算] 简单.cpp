/*
** Problem: https://leetcode-cn.com/problems/find-the-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/106988949
** Author: memcpy0
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for (const char &ch : s) c ^= ch;
        for (const char &ch : t) c ^= ch;
        return c;
    }
};