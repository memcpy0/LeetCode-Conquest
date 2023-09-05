/*
** Problem: https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays
** Article: https://memcpy0.blog.csdn.net/article/details/132688577
** Author: memcpy0
*/
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        s = set(nums1) & set(nums2)
        if s: return min(s) # 有交集
        x, y = min(nums1), min(nums2)
        return min(x * 10 + y, y * 10 + x)

// BEST: 位运算
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) mask1 |= 1 << x;
        for (int x : nums2) mask2 |= 1 << x;
        int m = mask1 & mask2;
        if (m) return __builtin_ctz(m); // 有交集
        int x = __builtin_ctz(mask1), y = __builtin_ctz(mask2);
        return min(x * 10 + y, y * 10 + x);
    }
}; 