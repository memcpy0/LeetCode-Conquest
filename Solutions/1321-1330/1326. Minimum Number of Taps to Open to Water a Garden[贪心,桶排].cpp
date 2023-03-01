/*
** Problem: https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/
** Article: https://memcpy0.blog.csdn.net/article/details/129288172
** Author: memcpy0
*/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> rightMost(n + 1);
        for (int i = 0; i <= n; ++i) {
            int r = ranges[i]; // r是半径
            if (i > r) rightMost[i - r] = i + r; // 对于i-r来说,i+r必然是它目前的最大值
            else rightMost[0] = max(rightMost[0], i + r);
        }
        int ans = 0;
        int curRight = 0, nextRight = 0; // 已建造的桥的右端点,下一座桥的右端点的最大值
        for (int i = 0; i < n; ++i) { // 注意这里没有遍历到n,因为它已经是终点了
            nextRight = max(nextRight, rightMost[i]);
            if (i == curRight) { // 到达已被覆盖的灌溉处的右端点 // 到达已建造的桥的右端点 
                if (i == nextRight) return -1; // 无论怎么开水龙头,都无法从i灌溉到i+1 // 无论怎么造桥，都无法从i到i+1
                curRight = nextRight; // 开能到最右处的水龙头 // 造一座桥
                ++ans;
            }
        }
        return ans;
    }
}; 