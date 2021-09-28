/*
** Problem: https://leetcode-cn.com/problems/power-of-four/
** Article: https://memcpy0.blog.csdn.net/article/details/117408777
** Author: memcpy0
*/
int ans[20] = {1,4,16,64,256,1024,4096,16384,65536,262144,1048576,4194304,16777216,67108864,268435456,1073741824};
class Solution {
public:
    bool isPowerOfFour(int n) { 
        if (n <= 0) return false;
        for (int i = 0; i < 16; ++i) if (n == ans[i]) return true;
        return false;
    }
};