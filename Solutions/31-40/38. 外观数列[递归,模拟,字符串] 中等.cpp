/*
** Problem: https://leetcode-cn.com/problems/count-and-say/
** Article: https://memcpy0.blog.csdn.net/article/details/106726954
** Author: memcpy0
*/
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string &&s = countAndSay(n - 1), ans; // 数段数的常用写法
        for (int i = 0, cnt = 1, len = s.size(); i < len; ++cnt, ++i) {
            if (i + 1 != len && s[i] == s[i + 1]) continue;
            ans += to_string(cnt) + s[i];
            cnt = 0;
        }
        return ans;
    }
};