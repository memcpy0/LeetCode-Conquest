/*
** Problem: https://leetcode-cn.com/problems/student-attendance-record-i/
** Article: https://memcpy0.blog.csdn.net/article/details/109556361
** Author: memcpy0
*/
class Solution {
public:
    bool checkRecord(string s) {
        int a = 0; //absent
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] == 'A' && ++a >= 2) return false;
            else if (s[i] == 'L' && i < n - 2 && s[i + 1] == 'L' && s[i + 2] == 'L') return false;
        }
        return true;
    }
};