/*
** Problem: https://leetcode.cn/problems/moving-stones-until-consecutive
** Article: https://memcpy0.blog.csdn.net/article/details/130448883
** Author: memcpy0
*/
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int s[3] = {a, b, c}; 
        sort(s, s + 3);
        a = s[0], b = s[1], c = s[2];
        return {c - a == 2 ? 0 : 
            c - b <= 2 || b - a <= 2 ? 1 : 2,
            c - a - 2};
    }
};