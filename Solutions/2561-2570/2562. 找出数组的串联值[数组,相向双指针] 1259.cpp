/*
** Problem: https://leetcode.cn/problems/find-the-array-concatenation-value
** Article: https://memcpy0.blog.csdn.net/article/details/133812172
** Author: memcpy0
*/
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            ans += (long long) stoll(to_string(nums[i]) + to_string(nums[j]));
        }
        if (n & 1) ans += (long long) nums[n / 2];
        return ans;
    }
};
// BEST: O(1)空间
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            int x = nums[i], y = nums[j];
            while (y) {
                x *= 10; 
                y /= 10;
            }
            ans += x + nums[j];
        }
        if (n & 1) ans += (long long) nums[n / 2];
        return ans;
    }
};