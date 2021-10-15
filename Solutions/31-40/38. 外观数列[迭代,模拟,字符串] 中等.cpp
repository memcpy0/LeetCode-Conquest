/*
** Problem: https://leetcode-cn.com/problems/count-and-say/
** Article: https://memcpy0.blog.csdn.net/article/details/106726954
** Author: memcpy0
*/
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; ++i) {
            string cur;
            for (int j = 0, cnt = 1, len = ans.size(); j < len; ++cnt, ++j) {
                if (j + 1 != len && ans[j] == ans[j + 1]) continue;
                cur += to_string(cnt) + ans[j];
                cnt = 0;
            }
            ans = cur;
        }
        return ans;
    }
};