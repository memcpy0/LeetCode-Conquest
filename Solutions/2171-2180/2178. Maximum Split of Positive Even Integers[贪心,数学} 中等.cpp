/*
** Problem: https://leetcode.cn/problems/maximum-split-of-positive-even-integers/
** Article: https://memcpy0.blog.csdn.net/article/details/131590605
** Author: memcpy0
*/
// BEST: 贪心+数学
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if (finalSum & 1) return ans;
        for (int i = 2; i <= finalSum; i += 2) {
            ans.push_back(i);
            finalSum -= i;
        }
        ans.back() += finalSum;
        return res;
    }
};