/*
** Problem: https://leetcode.cn/problems/minimum-swaps-to-make-strings-equal/
** Article: https://memcpy0.blog.csdn.net/article/details/129273478
** Author: memcpy0
*/
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int s1XCnt = 0, s1YCnt = 0;
        for (int i = 0, n = s1.size(); i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') ++s1XCnt;
                else ++s1YCnt;
            }
        }
        // s1XCnt = s2YCnt, s1YCnt = s2XCnt
        // 忽略匹配的字符;跳过不是同个字符的位置来观察(如将不同位置的x连着看,对面是连着的y)
        // 尽量用xx与对面同样位置yy(或者反过来这边用yy那边用xx)交换,这样交换次数最少,次数为s1XCnt/2+s1YCnt/2
        // 最后可能剩下一对xy与yx,要两次交换才行
        // 也可能都没剩下,之间返回
        // 如果最后只剩下一个x与一个y,则无解
        if (s1XCnt % 2 + s1YCnt % 2 == 1) return -1; // 这边只剩下一个x或y
        int ans = s1XCnt / 2 + s1YCnt / 2;
        return s1XCnt % 2 == 1 ? ans + 2 : ans;
    }
};