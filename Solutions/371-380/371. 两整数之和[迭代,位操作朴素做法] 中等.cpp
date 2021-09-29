/*
** Problem: https://leetcode-cn.com/problems/sum-of-two-integers/
** Article: https://memcpy0.blog.csdn.net/article/details/109349471
** Author: memcpy0
*/
class Solution {
public: 
    int getSum(int a, int b) {
        int ans = 0;
        for (int i = 0, carry = 0; i < 32; ++i) {
            int u1 = (a >> i) & 1, u2 = (b >> i) & 1;
            if (u1 == 1 && u2 == 1) {
                ans |= (carry << i);
                carry = 1;
            } else if (u1 == 1 || u2 == 1) {
                ans |= ((1 ^ carry) << i);
            } else {
                ans |= (carry << i);
                carry = 0;
            }
        }
        return ans;
    }
};