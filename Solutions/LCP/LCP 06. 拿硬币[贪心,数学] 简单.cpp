/*
** Problem: https://leetcode.cn/problems/na-ying-bi
** Article: https://memcpy0.blog.csdn.net/article/details/133682315
** Author: memcpy0
*/
class Solution {
public:
    int minCount(vector<int>& coins) {
        int sum = 0;
        for (int& i : coins) sum += (i + 1) / 2;
        return sum;
    }
};