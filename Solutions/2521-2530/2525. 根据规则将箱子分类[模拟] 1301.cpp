/*
** Problem: https://leetcode.cn/problems/categorize-box-according-to-criteria
** Article: https://memcpy0.blog.csdn.net/article/details/133938073
** Author: memcpy0
*/
// BEST
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool x = length >= 10000 || width >= 10000 || height >= 10000 || 
            1LL * length * width * height >= 1000000000;
        bool y = mass >= 100;
        if (x && y) return "Both";
        if (x) return "Bulky";
        if (y) return "Heavy";
        return "Neither";
    }
};