/*
** Problem: https://leetcode.cn/problems/count-days-spent-together/
** Article: https://memcpy0.blog.csdn.net/article/details/130198446
** Author: memcpy0
*/
class Solution {
private:
    int days[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        function<int(string)> f = [&](const string &a) {
            int m = (a[0] - '0') * 10 + (a[1] - '0');
            int d = (a[3] - '0') * 10 + (a[4] - '0');
            return days[m - 1] + d;
        };
        return max(min(f(leaveAlice), f(leaveBob)) - max(f(arriveAlice), f(arriveBob)) + 1, 0);
    }
};