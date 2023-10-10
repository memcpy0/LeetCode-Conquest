/*
** Problem: https://leetcode.cn/problems/split-with-minimum-sum/
** Article: https://memcpy0.blog.csdn.net/article/details/133741220
** Author: memcpy0
*/
// BEST
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int a[2]{};
        for (int i = 0; i < s.length(); i++)
            a[i % 2] = a[i % 2] * 10 + s[i] - '0'; // 按照奇偶下标分组
        return a[0] + a[1];
    }
};