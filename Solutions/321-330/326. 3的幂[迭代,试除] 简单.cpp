/*
** Problem: https://leetcode-cn.com/problems/power-of-three/
** Article: https://memcpy0.blog.csdn.net/article/details/120536998
** Author: memcpy0
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};