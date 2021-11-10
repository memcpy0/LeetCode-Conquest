/*
** Problem: https://leetcode-cn.com/problems/teemo-attacking/
** Article: https://memcpy0.blog.csdn.net/article/details/121259058
** Author: memcpy0
*/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, last = -1;
        for (const int &s : timeSeries) {
            int e = s + duration - 1;
            ans += last < s ? duration : e - last;
            last = e;
        }
        return ans;
    }
};