/*
** Problem: https://leetcode-cn.com/problems/distribute-candies/
** Article: https://memcpy0.blog.csdn.net/article/details/108810251
** Author: memcpy0
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size(), size = 0;  
        bitset<200010> bucket;
        for (int i = 0; i < n; ++i) {
            if (!bucket[candies[i] + 100000]) {
                ++size;
                bucket[candies[i] + 100000] = 1;
            }
        }
        return min(n / 2, size);
    }
};