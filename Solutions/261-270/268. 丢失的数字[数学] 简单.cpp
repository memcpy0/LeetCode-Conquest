/*
** Problem: https://leetcode-cn.com/problems/missing-number/
** Article: https://memcpy0.blog.csdn.net/article/details/106988398
** Author: memcpy0
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) 
            sum += (i - nums[i]);
        return sum + n;
    }
};