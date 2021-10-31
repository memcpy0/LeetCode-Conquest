/*
** Problem: https://leetcode-cn.com/problems/missing-number/
** Article: https://memcpy0.blog.csdn.net/article/details/106988398
** Author: memcpy0
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size(), ans = n;
        for (int i = 0; i < n; ++i)
            ans ^= (nums[i] ^ i);
		return ans;
	}
};