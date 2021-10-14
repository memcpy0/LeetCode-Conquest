/*
** Problem: https://leetcode-cn.com/problems/number-of-segments-in-a-string/
** Article: https://memcpy0.blog.csdn.net/article/details/109349573
** Author: memcpy0
*/
class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int tokensNum = 0;
        int beginPos = s.find_first_not_of(' ');
        int endPos = s.find_first_of(' ', beginPos);
        while (beginPos != string::npos) {
            ++tokensNum;
            beginPos = s.find_first_not_of(' ', endPos);
            endPos = s.find_first_of(' ', beginPos);
        }
        return tokensNum;
    }
};