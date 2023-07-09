/*
** Problem: https://leetcode.cn/problems/3sum/
** Article: https://memcpy0.blog.csdn.net/article/details/108933546
** Author: memcpy0
*/
// BEST: 排序+双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); 
        const int n = nums.size();
        for (int i = 0; i < n - 2; ++i) { //只搜索到倒数第三个数为止
            if (i > 0 && nums[i] == nums[i - 1]) continue; //去重剪枝,使用连续重复元素的第一个
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break; //后续循环不会有解
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue; //本次循环不会有解
            int newTarget = -nums[i], lo = i + 1, hi = n - 1; //三数变两数
            while (lo < hi) {
                int t = nums[lo] + nums[hi];
                if (t == newTarget) {
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) ++lo; //已经使用过的解元素
                    while (lo < hi && nums[hi] == nums[hi - 1]) --hi; //已经使用过的解元素
                    ++lo;
                    --hi;
                } else if (t < newTarget) {
                    while (lo < hi && nums[lo] == nums[lo + 1]) ++lo; //跳过无用的重复值
                    ++lo;
                } else {
                    while (lo < hi && nums[hi] == nums[hi - 1]) --hi; //跳过无用的重复值
                    --hi;
                }
            }
        } 
        return ans;
    }
};