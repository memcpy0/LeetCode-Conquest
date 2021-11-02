/*
** Problem: https://leetcode-cn.com/problems/complement-of-base-10-integer/
** Article: https://memcpy0.blog.csdn.net/article/details/108867646
** Author: memcpy0
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int temp = n, allOnes = 0;
        while (temp > 0) {
            temp >>= 1;
            allOnes = (allOnes << 1) | 1; 
        }
        return n ^ allOnes;
    }
};