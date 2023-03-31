/*
** Problem: https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points/
** Article: https://memcpy0.blog.csdn.net/article/details/129891854
** Author: memcpy0
*/

// 桶排+估算最大间距
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> nums;
        for (auto& p : points) {
            nums.push_back(p[0]);
        }
        const int inf = 1 << 30;
        int mi = inf, mx = -inf;
        for (int v : nums) {
            mi = min(mi, v);
            mx = max(mx, v);
        }
        int bucketSize = max(1, (mx - mi) / (n - 1)); // 桶大小,桶中任意元素的差<bucketSize
        int bucketCount = (mx - mi) / bucketSize + 1; // 桶数量,相当于[mi,mx]这段区间分成bucketCount个大小bucketSize的区间
        vector<pair<int, int>> buckets(bucketCount, {inf, -inf});
        for (int v : nums) {
            int i = (v - mi) / bucketSize; // 计算该值放入哪个桶
            buckets[i].first = min(buckets[i].first, v);
            buckets[i].second = max(buckets[i].second, v);
        }
        int ans = 0, prev = inf;
        for (auto [curmin, curmax] : buckets) {
            if (curmin > curmax) continue; // 这个桶中没有值
            ans = max(ans, curmin - prev);
            prev = curmax;
        }
        return ans;
    }
};

/*
// 快排
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            ans = max(ans, points[i + 1][0] - points[i][0]);
        }
        return ans;
    }
};
*/