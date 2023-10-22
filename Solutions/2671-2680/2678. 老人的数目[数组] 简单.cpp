/*
** Problem: https://leetcode.cn/problems/number-of-senior-citizens/
** Article: https://memcpy0.blog.csdn.net/article/details/133980706
** Author: memcpy0
*/
class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [&](const string &a) {
            return a.substr(11, 2) > "60";
        });
    }
};