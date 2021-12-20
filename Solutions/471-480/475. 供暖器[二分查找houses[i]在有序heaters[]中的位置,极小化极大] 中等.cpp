/*
** Problem: https://leetcode-cn.com/problems/heaters/
** Article: https://memcpy0.blog.csdn.net/article/details/108963774
** Author: memcpy0
*/
class Solution {
public:
    // 对于每座房子的前后两个供暖器(只一个供暖器时另外判断),
    // 寻找供暖器离房屋的较小距离,即这座房子需要的最小加热半径
    // 在这一过程中,不断更新当前最大加热半径 
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int m = houses.size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            int needRadius = INT_MAX; // houses[i]需要的最小供热半径
            // 找到heaters[]中第一个>=houses[i]的供暖器位置
            // 即右侧离这座房子最近的供暖器
            auto &&right = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            if (right != heaters.end())          // 说明房子右侧有供暖器
                needRadius = *right - houses[i]; // 它们之间的距离
            if (right != heaters.begin()) { // 说明房子左侧有供暖器
                auto &&left = right - 1;    // 左边供暖器的位置就是当前larger位置-1
                needRadius = min(needRadius, houses[i] - *left); // 比较二者较房子的距离
            }
            ans = max(ans, needRadius);
        }
        return ans;
    }
};