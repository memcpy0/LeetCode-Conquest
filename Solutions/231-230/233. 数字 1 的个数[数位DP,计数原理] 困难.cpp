/*
** Problem: https://leetcode-cn.com/problems/number-of-digit-one/
** Article: https://memcpy0.blog.csdn.net/article/details/119744426
** Author: memcpy0
*/
class Solution {
public:
    int countDigitOne(int n) { 
        int ans = 0;
        long long r = 1;
        while (r <= n) { //分别计算个、十、百......千位上1出现的次数,再求和
            int a = n / (r * 10), b = n / r % 10, c = n % r;
            switch (b) {
                case 0: ans += a * r; break;
                case 1: ans += a * r + c + 1; break;
                default: ans += (a + 1) * r; break;
            }
            r *= 10; //不然r可能溢出
        } 
        return ans;
    } 
};