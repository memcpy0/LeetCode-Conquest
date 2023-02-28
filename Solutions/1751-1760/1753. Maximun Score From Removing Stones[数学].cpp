/*
** Problem: https://leetcode.cn/problems/maximum-score-from-removing-stones/description/
** Article: https://blog.csdn.net/myRealization/article/details/129273423
** Author: memcpy0
*/
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a + b <= c) return a + b;
        if (a + c <= b) return a + c;
        if (b + c <= a) return b + c;
        return (a + b + c) / 2;
    }
};