/*
** Problem: https://leetcode-cn.com/problems/number-of-boomerangs/
** Article: https://memcpy0.blog.csdn.net/article/details/120275350
** Author: memcpy0
*/
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;
        int ans = 0;
        unordered_map<int, int> rec;
        for (int i = 0, n = points.size(); i < n; ++i) {
            //对于points[i],计算其他点和它之间的距离,以x^2+y^2为距离
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int x2 = points[j][0], y2 = points[j][1];
                int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                ++rec[dist];
            }
            //如果有k个点和points[i]距离相同,则回旋镖数量+A(k,2)
            for (const auto &it : rec)
                if (it.second >= 2) ans += it.second * (it.second - 1);
            rec.clear();
        }
        return ans;
    }
};