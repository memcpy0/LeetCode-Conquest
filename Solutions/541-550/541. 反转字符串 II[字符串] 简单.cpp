/*
** Problem: https://leetcode-cn.com/problems/reverse-string-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/108963124
** Author: memcpy0
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0, n = s.size(); i < n; i += 2 * k) {
            auto send = (i + k > n) ? s.end() : (s.begin() + i + k);
            reverse(s.begin() + i, send);
        }   
        return s;
    }
};