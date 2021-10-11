/*
** Problem: https://leetcode-cn.com/problems/integer-to-english-words/
** Article: https://memcpy0.blog.csdn.net/article/details/120714218
** Author: memcpy0
*/
vector<string> num2str_lo = {
    "Zero",
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
vector<string> num2str_med = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
vector<string> num2str_hi = {
    "Billion", "Million", "Thousand", ""
};
int group[4] = {(int)1e9, (int)1e6, (int)1e3, 1};
class Solution {
private:
    string num2str(int x) {
        string ans;
        if (x >= 100) {
            ans += num2str_lo[x / 100] + " Hundred ";
            x %= 100;
        }
        if (x >= 20) {
            ans += num2str_med[x / 10] + " ";
            x %= 10;
        }
        if (x != 0) ans += num2str_lo[x] + " ";
        return ans;
    }
public:
    string numberToWords(int num) {
        if (!num) return num2str_lo[0]; // 特判0
        string ans;
        for (int i = 0; i < 4; ++i) {
            if (num < group[i]) continue; // 该数达不到对应位数(长度不够,对应的几位为0)
            ans += num2str(num / group[i]) + num2str_hi[i] + " ";
            num %= group[i];
        }
        while (ans.back() == ' ') ans.pop_back(); // 有时结尾可能有多余的空格
        return ans;
    }
};