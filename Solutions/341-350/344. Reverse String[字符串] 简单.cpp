/*
** Problem: https://leetcode.cn/problems/reverse-string/
** Article: https://memcpy0.blog.csdn.net/article/details/108963038
** Author: memcpy0
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]);
    }
};
