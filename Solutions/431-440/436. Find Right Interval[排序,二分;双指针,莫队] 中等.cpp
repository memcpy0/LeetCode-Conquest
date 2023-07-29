/*
** Problem: https://leetcode.cn/problems/find-right-interval/
** Article: https://memcpy0.blog.csdn.net/article/details/131993956
** Author: memcpy0
*/
// BEST: 排序+二分
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> itsStart;
        for (int i = 0; i < n; ++i) itsStart.emplace_back(intervals[i][0], i);
        sort(itsStart.begin(), itsStart.end());
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (itsStart[mid].first >= intervals[i][1]) r = mid;
                else l = mid + 1;
            }
            ans[i] = l == n ? -1 : itsStart[l].second;
        }
        return ans;
    }
};
// 排序+双指针+莫队
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++) {
            while (j < n && endIntervals[i].first > startIntervals[j].first)
                j++;
            if (j < n)
                ans[endIntervals[i].second] = startIntervals[j].second;
        }
        return ans;
    }
};