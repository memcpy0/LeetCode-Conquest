/*
** Problem: https://leetcode-cn.com/problems/arranging-coins/
** Article: https://memcpy0.blog.csdn.net/article/details/119641437
** Author: memcpy0
*/
class Solution {
public:
    int arrangeCoins(int n) { 
        using ll = long long;
        ll l = 1, r = n;
        while (l < r) {
            ll mid = l + r + 1 >> 1;
            if (mid * (mid + 1) / 2 <= n) l = mid;
            else r = mid - 1;
        }
        return static_cast<int>(l);
    }
};