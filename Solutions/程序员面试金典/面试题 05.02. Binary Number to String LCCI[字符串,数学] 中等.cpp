/*
** Problem: https://leetcode.cn/problems/bianry-number-to-string-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/129329773
** Author: memcpy0
*/
class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (ans.size() <= 8 && num > 1e-10) { // 6位小数,8位字符
            int f = num * 2;
            ans.push_back('0' + f);
            num = num * 2 - f;
        }
        return ans.size() <= 8 ? ans : "ERROR";
    }
};