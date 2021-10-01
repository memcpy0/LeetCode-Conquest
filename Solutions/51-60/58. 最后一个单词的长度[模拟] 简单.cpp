/*
** Problem: https://leetcode-cn.com/problems/length-of-last-word/
** Article: https://memcpy0.blog.csdn.net/article/details/120545600
** Author: memcpy0
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size() - 1, len = 0;
        while (j >= 0 && s[j] == ' ') --j; //跳过空格
        while (j >= 0 && s[j] != ' ') ++len, --j; //计算最后一个单词长度
        return len;
    }
};