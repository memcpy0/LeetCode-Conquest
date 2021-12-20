/*
** Problem: https://leetcode-cn.com/problems/heaters/
** Article: https://memcpy0.blog.csdn.net/article/details/108963774
** Author: memcpy0
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = houses.size(), n = heaters.size(), l = 0, r = max(houses.back(), heaters.back());
        while (l < r) {
            int mid = l + r >> 1, i, j;
            for (i = 0, j = 0; i < m && j < n; ++j)
                while (i < m && houses[i] >= heaters[j] - mid && houses[i] <= heaters[j] + mid) ++i;
            if (i >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};