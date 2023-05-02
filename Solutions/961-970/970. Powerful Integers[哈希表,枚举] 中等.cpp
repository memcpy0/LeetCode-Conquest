/*
** Problem: https://leetcode.cn/problems/powerful-integers
** Article: https://memcpy0.blog.csdn.net/article/details/130463865
** Author: memcpy0
*/
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        for (int a = 1; a <= bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                ans.insert(a + b);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};