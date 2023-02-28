/*
** Problem: https://leetcode.cn/problems/find-positive-integer-solution-for-a-given-equation/
** Article: https://memcpy0.blog.csdn.net/article/details/129273472
** Author: memcpy0
*/
/*
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        for (int x = 1; x <= 1000; ++x) {
            for (int y = 1; y <= 1000; ++y) {
                if (customfunction.f(x, y) == z) ans.push_back({x, y});
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        for (int x = 1; x <= 1000; ++x) {
            int yl = 1, yh = 1000;
            while (yl <= yh) {
                int mid = (yl + yh) / 2, tz = customfunction.f(x, mid);
                if (tz == z) {
                    ans.push_back({x, mid});
                    break;
                } 
                else if (tz > z) yh = mid - 1; // 说明y太大了
                else yl = mid + 1;
            }
        }
        return ans;
    }
};