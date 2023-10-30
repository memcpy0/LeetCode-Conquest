/*
** Problem: https://leetcode.cn/problems/h-index-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/118686492
** Author: memcpy0
*/
// BEST
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), l = 0, h = n;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (citations[m] >= n - m) h = m;
            else l = m + 1;
        }
        return n - l;
    }
};