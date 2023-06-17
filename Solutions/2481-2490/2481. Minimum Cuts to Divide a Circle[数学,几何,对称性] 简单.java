/*
** Problem: https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/
** Article: https://memcpy0.blog.csdn.net/article/details/131263454
** Author: memcpy0
*/
class Solution {
    public int numberOfCuts(int n) {
        if (n == 1) return 0;
        return (n % 2 == 0) ? n / 2 : n;
    }
}