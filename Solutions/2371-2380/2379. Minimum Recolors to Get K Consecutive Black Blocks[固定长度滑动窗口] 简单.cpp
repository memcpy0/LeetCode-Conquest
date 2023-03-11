/*
** Problem: https://leetcode-cn.com/problems/find-longest-subarray-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/129466606
** Author: memcpy0
*/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), wnum = 0;
        // 前k个字符中W的数量
        for (int i = 0; i < k; ++i)
            wnum += (blocks[i] == 'W'); // 长度为k的滑窗
        int ans = wnum;
        for (int i = k; i < n; ++i) {
            if (blocks[i] == 'W') ++wnum; // 向右扩张一步,是白方块则+1
            if (blocks[i - k] == 'W') --wnum;
            ans = min(ans, wnum);
        }
        return ans;
    }
};