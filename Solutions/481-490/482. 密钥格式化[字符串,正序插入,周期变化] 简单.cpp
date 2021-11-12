/*
** Problem: https://leetcode-cn.com/problems/license-key-formatting/
** Article: https://memcpy0.blog.csdn.net/article/details/108871763
** Author: memcpy0
*/
class Solution { 
public:
    string licenseKeyFormatting(string s, int k) { 
    	// num=k-字母数字个数%k,
    	// num != k则num为(k-第一组大小),否则num = k
        int num = k - (s.size() - count(s.begin(), s.end(), '-')) % k; 
        string ans;
        for (const char &c : s) {
            if (c == '-') continue; 
            if (num == 0 && !ans.empty()) ans += '-'; // 不知道组数
            ans.push_back(toupper(s[i]));
            num = (num + 1) % k; // 从0到num-1不断循环
        }
        return ans;
    }
};