/*
** Problem: https://leetcode-cn.com/problems/range-addition-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/109627465
** Author: memcpy0
*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r = m, c = n;
        for (int i = 0, size = ops.size(); i < size; ++i) {
            r = min(r, ops[i][0]);
            c = min(c, ops[i][1]);
        } 
        return r * c;
    }
};