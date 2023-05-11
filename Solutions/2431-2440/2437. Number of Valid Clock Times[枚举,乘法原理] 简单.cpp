/*
** Problem: https://leetcode.cn/problems/number-of-valid-clock-times/description/
** Article: https://memcpy0.blog.csdn.net/article/details/130626897
** Author: memcpy0
*/
class Solution {
public:
    int countTime(string time) {
        function<int(string, int)> count = [&](string t, int period) {
            int ans = 0;
            for (int i = 0; i < period; ++i)
                if ((t[0] == '?' || t[0] - '0' == i / 10)
                    && (t[1] == '?' || t[1] - '0' == i % 10)) ++ans;
            return ans;
        };
        return count(time.substr(0, 2), 24) * count(time.substr(3), 60);
    }
};