/*
** Problem: https://leetcode-cn.com/problems/distribute-candies/
** Article: https://memcpy0.blog.csdn.net/article/details/108810251
** Author: memcpy0
*/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> rec(candyType.begin(), candyType.end());
        return min(candyType.size() / 2, rec.size());
    }
};