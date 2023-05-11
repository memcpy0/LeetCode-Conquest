/*
** Problem: https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/
** Article: https://memcpy0.blog.csdn.net/article/details/130626437
** Author: memcpy0
*/
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] rec = new int[60];
        int ans = 0;
        for (int t : time) {
            int r = t % 60; 
            ans += rec[r == 0 ? 0 : 60 - r]; //如果为0,找其他为0的数;不为0,找相加为60的数
            ++rec[r];
        }
        return ans;
    }
}