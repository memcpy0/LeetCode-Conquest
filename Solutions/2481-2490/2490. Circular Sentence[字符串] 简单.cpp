/*
** Problem: https://leetcode.cn/problems/circular-sentence/
** Article: https://memcpy0.blog.csdn.net/article/details/131521682
** Author: memcpy0
*/
// BEST
class Solution {
public:
    bool isCircularSentence(string s) {
        if (s[0] != s.back()) return false;
        for (int i = 1, n = s.size(); i < n - 1; ++i) 
            if (s[i] == ' ' && s[i - 1] != s[i + 1]) return false;
        return true;
    }
};