/*
** Problem: https://leetcode.cn/problems/masking-personal-information/
** Article: https://memcpy0.blog.csdn.net/article/details/120574576
** Author: memcpy0
*/
class Solution {
private:
    vector<string> country = {"", "+*-", "+**-", "+***-"};
public:
    string maskPII(string s) {
        size_t idx = s.find('@'); // 有就是邮箱
        if (idx != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower); // 全部小写
            return s.substr(0, 1) + "*****" + s.substr(idx - 1);
            // 名字第一个字母,中间字母用*****替换,名字最后一个字母和后面的域名不变
        }
        s = regex_replace(s, regex("[^0-9]"), ""); // 非数字字符替换为空
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    }
};