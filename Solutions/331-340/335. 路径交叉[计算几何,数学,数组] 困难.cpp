/*
** Problem: https://leetcode-cn.com/problems/self-crossing/
** Article: https://memcpy0.blog.csdn.net/article/details/121039478
** Author: memcpy0
*/
class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        if (d.size() <= 3) return false; // 3条边,不可能相交
        // 不可能与d[i-1],d[i-2]对应的边相交
        for (int i = 3, n = d.size(); i < n; ++i) {
            // d[i]对应的边和d[i-3]对应的边相交
            if (d[i] >= d[i - 2] && d[i - 1] <= d[i - 3]) return true;
            // d[i]对应的边和上一个逆时针四边形移动是否相交
            // d[i]对应的边和d[i - 4]对应的边相交
            if (i >= 4 && d[i - 1] == d[i - 3] && d[i] + d[i - 4] >= d[i - 2]) return true;
            // d[i]对应的边和d[i - 5]对应的边相交
            if (i >= 5 && 
                d[i - 1] <= d[i - 3] && d[i - 1] + d[i - 5] >= d[i - 3] &&
                d[i - 2] > d[i - 4] && d[i] >= d[i - 2] - d[i - 4]) // 注意边界条件
                return true;
        }
        return false;
    }
};