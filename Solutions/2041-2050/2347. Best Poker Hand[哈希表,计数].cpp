/*
** Problem: https://leetcode.cn/problems/best-poker-hand
** Article: https://memcpy0.blog.csdn.net/article/details/129273445
** Author: memcpy0
*/
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int rcnt[14] = {0}, scnt[4] = {0};
        for (int i = 0; i < 5; ++i) {
            ++scnt[suits[i] - 'a'];
            ++rcnt[ranks[i]];
        }
        for (int i = 0; i < 4; ++i) if (scnt[i] == 5) return "Flush";
        bool three = false, pair = false;
        for (int i = 1; i <= 13; ++i) {
            if (rcnt[i] >= 3) three = true;
            else if (rcnt[i] == 2) pair = true;
        }
        if (three) return "Three of a Kind";
        else if (pair) return "Pair";
        return "High Card";
    }
};

