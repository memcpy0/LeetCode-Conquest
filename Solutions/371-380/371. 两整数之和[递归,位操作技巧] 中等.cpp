/*
** Problem: https://leetcode-cn.com/problems/sum-of-two-integers/
** Article: https://memcpy0.blog.csdn.net/article/details/109349471
** Author: memcpy0
*/
class Solution {
public:
    int getSum(int a, int b) {
        return !b ? a : getSum(a ^ b, static_cast<uint32_t>(a & b) << 1);
    }
};