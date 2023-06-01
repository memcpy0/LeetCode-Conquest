/*
** Problem: https://leetcode.cn/problems/magnetic-force-between-two-balls
** Article: https://memcpy0.blog.csdn.net/article/details/130998113 
** Author: memcpy0
*/
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0, r = (position[n - 1] - position[0]) / (m - 1);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int cnt = 1;
            // for (int i = 0, j; i < n; i = j) {
            //     j = lower_bound(position.begin() + i + 1, position.end(),
            //         position[i] + mid) - position.begin();
            //     if (j != n) ++cnt; // 找到一个数position[j],和position[i]差>=mid
            // }
            for (int pre = position[0], i = 1; i < n; ++i) {
                if (position[i] >= pre + mid) {
                    pre = position[i];
                    ++cnt;
                }
            }
            if (cnt >= m) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};