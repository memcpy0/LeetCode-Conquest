/*
** Problem: https://leetcode.cn/problems/number-of-arithmetic-triplets
** Article: https://memcpy0.blog.csdn.net/article/details/129891839
** Author: memcpy0
*/
// 同向三指针
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0, i = 0, j = 1; 
        for (int x : nums) {
            while (nums[j] + diff < x) ++j; // 直到nums[j]+diff>=x
            if (nums[j] + diff != x) continue;
            while (nums[i] + diff < nums[j]) ++i;
            if (nums[i] + diff == nums[j]) ++ans;
        }
        return ans;
    }
};

/*
// 哈希表+一次遍历
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        unordered_set<int> rec;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (rec.find(nums[i] - 2 * diff) != rec.end()
                && rec.find(nums[i] - diff) != rec.end())
                ++ans;
            rec.insert(nums[i]);
        }
        return ans;
    }
};
*/

/*
// 哈希表+二次遍历
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        unordered_set<int> rec(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n; ++i)
            if (rec.find(nums[i] - diff) != rec.end()
                && rec.find(nums[i] + diff) != rec.end())
                ++ans;
        return ans;
    }
};
*/