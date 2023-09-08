/*
** Problem: https://leetcode.cn/problems/calculate-delayed-arrival-time
** Article: https://memcpy0.blog.csdn.net/article/details/132767644
** Author: memcpy0
*/
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};