/*
** Problem: https://leetcode.cn/problems/number-of-valid-clock-times/description/
** Article: https://memcpy0.blog.csdn.net/article/details/130626897
** Author: memcpy0
*/
class Solution {
public:
    int countTime(string time) {
        int a = 1, b = 1;
        a = time[0] == '?' ? (time[1] == '?' ? 24 :
            (time[1] < '4' ? 3 : 2)) :
            (time[1] == '?' ? (time[0] == '2' ? 4 : 10) : 1);
        b = (time[3] == '?' ? 6 : 1) * (time[4] == '?' ? 10 : 1);
        return a * b;
    }
};