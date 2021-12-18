/*
** Problem: https://leetcode-cn.com/problems/water-bottles/
** Article: https://memcpy0.blog.csdn.net/article/details/122007151
** Author: memcpy0
*/
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, numEmpty = numBottles; // 喝完已有的酒
        while (numEmpty >= numExchange) {
            int q = numEmpty / numExchange, r = numEmpty % numExchange;
            ans += q; // 新换的q瓶酒被喝完
            numEmpty = q + r; // 喝完兑换的酒后,空瓶的数量
        }
        return ans;
    }
}