/*
** Problem: https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
** Article: https://memcpy0.blog.csdn.net/article/details/134090084
** Author: memcpy0
*/
// BEST
class Solution {
    int get_max_size(int size, vector<int> &cuts) {
        sort(cuts.begin(), cuts.end());
        int res = max(cuts[0], size - cuts.back());
        for (int i = 1; i < cuts.size(); i++) {
            res = max(res, cuts[i] - cuts[i - 1]);
        }
        return res;
    }
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        int max_h = get_max_size(h, horizontalCuts);
        int max_w = get_max_size(w, verticalCuts);
        return (long long) max_h * max_w % 1'000'000'007;
    }
};