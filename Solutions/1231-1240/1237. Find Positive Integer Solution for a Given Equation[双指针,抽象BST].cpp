/*
** Problem: https://leetcode.cn/problems/find-positive-integer-solution-for-a-given-equation/
** Article: https://memcpy0.blog.csdn.net/article/details/129273472
** Author: memcpy0
*/
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int x = 1, y = 1000; // x向右,f=(x,y)递增,y向下,f(x,y)递减
        while (x <= 1000 && y >= 1) {
            int tz = customfunction.f(x, y);
            if (tz == z) { // x,y合适
                ans.push_back({x, y});
                ++x; // 或者--y
            } else if (tz < z) ++x; // tz太小,增加x以增加tz
            else --y; // tz太大,减少y以减少tz
        }
        return ans;
    }
};