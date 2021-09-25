/*
** Problem: https://leetcode-cn.com/problems/sum-of-beauty-in-the-array/
** Article: https://memcpy0.blog.csdn.net/article/details/120476571
** Author: memcpy0
*/
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> prefix(n), suffix(n); //prefix[i]表示[0,i)之间的最大值,suffix[i]表示(i,n-1]之间的最小值
        prefix[0] = 0, suffix[n - 1] = 100001;
        for (int i = 1; i < n; ++i) { //合并起来
            prefix[i] = max(nums[i - 1], prefix[i - 1]);
            suffix[n - i - 1] = min(nums[n - i], suffix[n - i]);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > prefix[i] && nums[i] < suffix[i]) ans += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) ++ans;
        }
        return ans;
    }   
};