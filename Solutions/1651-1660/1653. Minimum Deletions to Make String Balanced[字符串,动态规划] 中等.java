/*
** Problem: https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/
** Article: https://memcpy0.blog.csdn.net/article/details/129405037
** Author: memcpy0
*/
class Solution {
    public int minimumDeletions(String s) {
        int bComeBeforeA = 0, minDel = 0;
        for (int i = 0, n = s.length(); i < n; ++i) {
            char c = s.charAt(i);
            // c前面的字符串已经平衡,如果前面存在'b',则最后的'a'会失衡
            if (c == 'a') {
                // 要么删除前面的'b',要么删除这里的'a'
                // 看哪种做法删除数最少
                minDel = Math.min(bComeBeforeA, minDel + 1);
            } else ++bComeBeforeA; // 最后一个字符是'b',不会导致失衡
        }
        return minDel;
    }
}