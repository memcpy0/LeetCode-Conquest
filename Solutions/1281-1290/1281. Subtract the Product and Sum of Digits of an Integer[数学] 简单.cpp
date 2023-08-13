/*
** Problem: https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer
** Article: https://memcpy0.blog.csdn.net/article/details/107838668
** Author: memcpy0
*/
// BEST: 模拟
class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;
        while (n) {
            int t = n % 10;
            prod *= t;
            sum += t;
            n /= 10;
        }
        return prod - sum;
    }
};