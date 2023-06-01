/*
** Problem: https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/
** Article: https://memcpy0.blog.csdn.net/article/details/130998076 
** Author: memcpy0
*/
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int l = 0, r = (price[n - 1] - price[0]) / (k - 1);
        while (l < r) {
            int mid = (l + r + 1) / 2; // [l,r+1)
            int cnt = 1; // 以mid为礼盒最大甜蜜度
            // 枚举数组price,看能否找到相差至少为mid的k个数
            // 下面这种写法只超过8%
            // for (int i = 0, j; i < n; i = j) {
            //     j = lower_bound(price.begin() + i + 1, price.end(), price[i] + mid) - price.begin();
            //     if (j != n) ++cnt; // 找到一个数price[j],和price[i]差>=mid
            // }
            for (int pre = price[0], i = 1; i < n; ++i) {
                if (price[i] >= pre + mid) {
                    ++cnt;
                    pre = price[i];
                }
            }
            if (cnt >= k) l = mid; // 可满足最大甜蜜度为mid
            else r = mid - 1;
        }
        return l;
    }
}; 