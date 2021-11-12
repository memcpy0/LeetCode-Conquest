/*
** Problem: https://leetcode-cn.com/problems/detect-capital/
** Article: https://memcpy0.blog.csdn.net/article/details/109555817
** Author: memcpy0
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        int u = count_if(word.begin(), word.end(), [](const char &c) {
            return isupper(c);
        }); // 全大写、全小写、一个大写、只有首字母大写
        return u == word.size() || !u || (u == 1 && isupper(word[0]));
    }
};