/*
** Problem: https://leetcode-cn.com/problems/sqrtx/
** Article: https://memcpy0.blog.csdn.net/article/details/121135932
** Author: memcpy0
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x; // 0->0, 1->1
        // 找到第一个自乘后大于x的数
        int l = 0, r = x;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long t = (long long)mid * mid;
            if (t > x) r = mid;
            else l = mid + 1;
        }
        return l - 1;
    }
};