/*
** Problem: https://leetcode-cn.com/problems/license-key-formatting/
** Article: https://memcpy0.blog.csdn.net/article/details/108871763
** Author: memcpy0
*/
class Solution {
private:
    void allocate(const string &s, string &t, int count, int &idx) {
        while (count--) {
            while (!isalnum(s[idx])) ++idx;
            t.push_back(toupper(s[idx++]));
        }
    }
public:
    string licenseKeyFormatting(string s, int k) { 
        int alnum = (s.size() - count(s.begin(), s.end(), '-')), firstGroupNum = alnum % k;
        int groups = alnum / k + (firstGroupNum != 0), idx = 0;
        string ans;
        for (int i = 0; i < groups; ++i) {
            if (i == 0 && firstGroupNum != 0) allocate(s, ans, firstGroupNum, idx); //分配第一组的字母或数字
            else allocate(s, ans, k, idx); //分配其他组的字母或数字
            if (i != groups - 1) ans.push_back('-'); // 知道组数
        }
        return ans;
    }
};