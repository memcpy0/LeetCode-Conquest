/*
** Problem: https://leetcode-cn.com/problems/arithmetic-slices
** Article: https://memcpy0.blog.csdn.net/article/details/119641437
** Author: memcpy0
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() <= 2) return 0;
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n - 2; ) {
            int j = i, d = nums[i + 1] - nums[i];
            while (j + 1 < n && nums[j + 1] - nums[j] == d) ++j;
            int len = j - i + 1, a0 = 1, an = len - 3 + 1;
            //符合条件(长度>=3且<=len)的等差子数组的数量
            int cnt = (a0 + an) * an / 2;
            ans += cnt;
            i = j;
        } 
        return ans;
    }
};