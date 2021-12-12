/*
** Problem: https://leetcode-cn.com/problems/to-lower-case/
** Article: https://memcpy0.blog.csdn.net/article/details/107632888
** Author: memcpy0
*/
class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) if (isalpha(c)) c |= 32;
        return s;
    }
};