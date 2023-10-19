/*
** Problem: https://leetcode.cn/problems/tuple-with-same-product/
** Article: https://memcpy0.blog.csdn.net/article/details/133919279
** Author: memcpy0
*/
// BEST
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i ++)
            for (int j = i + 1; j < nums.size(); j++)
                ++cnt[nums[i] * nums[j]];
        for (auto it : cnt) 
            ans += it.second * (it.second - 1) * 4;   
        return ans;
    }
};