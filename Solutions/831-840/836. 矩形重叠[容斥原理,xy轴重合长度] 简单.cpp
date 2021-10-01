/*
** Problem: https://leetcode-cn.com/problems/rectangle-overlap/
** Article: https://memcpy0.blog.csdn.net/article/details/120574576
** Author: memcpy0
*/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int lx = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        int ly = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
        return lx > 0 && ly > 0;
    }
};