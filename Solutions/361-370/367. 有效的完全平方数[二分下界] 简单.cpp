/*
** Problem: https://leetcode-cn.com/problems/valid-perfect-square/
** Article: https://memcpy0.blog.csdn.net/article/details/109349499
** Author: memcpy0
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) { // 找到第一个自乘后大于等于num的数
            int mid = l + (r - l) / 2;
            long long t = (long long)mid * mid;
            if (t >= num) r = mid;
            else l = mid + 1;
        }
        return (long long)l * l == num;
    }
};