/*
** Problem: https://leetcode-cn.com/problems/day-of-the-year/
** Article: https://memcpy0.blog.csdn.net/article/details/122117185
** Author: memcpy0
*/
int months[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int isLeap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        return (m > 2 && isLeap(y) ? months[m - 1] + 1 : months[m - 1]) + d;
    }
};