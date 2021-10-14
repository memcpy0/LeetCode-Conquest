/*
** Problem: https://leetcode-cn.com/problems/number-of-segments-in-a-string/
** Article: https://memcpy0.blog.csdn.net/article/details/109349573
** Author: memcpy0
*/
class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; ) {
            if (s[i] == ' ') { ++i; continue; }
            while (i < n && s[i] != ' ') ++i;
            ++ans;
        }
        return ans;
    }
};