/*
** Problem: https://leetcode-cn.com/problems/power-of-three/
** Article: https://memcpy0.blog.csdn.net/article/details/120536998
** Author: memcpy0
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};