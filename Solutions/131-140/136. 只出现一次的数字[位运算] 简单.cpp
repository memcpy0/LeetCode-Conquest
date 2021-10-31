/*
** Problem: https://leetcode-cn.com/problems/single-number/
** Article: https://memcpy0.blog.csdn.net/article/details/106988806
** Author: memcpy0
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto &i : nums) ans ^= i;
        return ans;
    }
};