/*
** Problem: https://leetcode-cn.com/problems/power-of-three/
** Article: https://memcpy0.blog.csdn.net/article/details/120536998
** Author: memcpy0
*/
int ans[25] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        for (int i = 0; i < 20; ++i) if (n == ans[i]) return true;
        return false;
    }
};