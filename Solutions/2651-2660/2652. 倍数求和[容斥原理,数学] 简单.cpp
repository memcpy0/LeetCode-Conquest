/*
** Problem: https://leetcode.cn/problems/sum-multiples/
** Article: https://memcpy0.blog.csdn.net/article/details/133882566
** Author: memcpy0
*/
class Solution {
private:
    int s(int n, int m) {
        return n / m * (n / m + 1) / 2 * m; // n/m=k,说明[1,n]中为m倍数的数有k个
    }
public:
    int sumOfMultiples(int n) {
        return s(n, 3) + s(n, 5) + s(n, 7) - s(n, 15) - s(n, 21) - s(n, 35) + s(n, 105);
    }
};