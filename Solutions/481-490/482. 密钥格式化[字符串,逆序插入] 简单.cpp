/*
** Problem: https://leetcode-cn.com/problems/license-key-formatting/
** Article: https://memcpy0.blog.csdn.net/article/details/108871763
** Author: memcpy0
*/
class Solution {
public:
    string licenseKeyFormatting(string s, int k) { 
        string ans;
        for (int i = s.size() - 1, cnt = 0; i >= 0; --i) {
            if (s[i] == '-') continue;
            if (cnt == k) { // 不知道组数
                ans.push_back('-');
                cnt = 0;
            }
            ans.push_back(toupper(s[i])); // 全大写字母或数字
            ++cnt;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};