/*
** Problem: https://leetcode-cn.com/problems/maximum-number-of-visible-points/
** Article: https://memcpy0.blog.csdn.net/article/details/121986872
** Author: memcpy0
*/
class Solution {
private:
    using Point = vector<int>;
    const double pi = acos(-1.0), eps = 1e-8;
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int x = location[0], y = location[1];
        int onLocal = 0; // 和location重合的点
        vector<double> polars;
        for (const Point &p : points) {
            if (p[0] == x && p[1] == y) { ++onLocal; continue; } // 这些点一定能看到
            polars.push_back(atan2(p[1] - y, p[0] - x));
        }
        sort(polars.begin(), polars.end(), [&](const double &a, const double &b) {
            return a - b < -eps; // 极角从小到大排序
        });
        for (int i = 0, n = polars.size(); i < n; ++i)
            polars.push_back(polars[i] + 2 * pi); // 避免漏掉解
        double radian = angle * pi / 180;
        int maxlen = 0;
        int l = 0, r = 0, n = polars.size();
        while (true) { // 滑动窗口
            while (r < n && polars[r] - polars[l] <= radian) ++r; // 窗口扩张
            maxlen = max(maxlen, r - l);
            if (r >= n) break;
            while (l < r && polars[r] - polars[l] > radian) ++l; // 窗口收缩
        }
        return maxlen + onLocal;
    }
};