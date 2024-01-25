/*
** Problem: https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/
** Article: https://memcpy0.blog.csdn.net/article/details/135854970
** Author: memcpy0
*/
// cpp
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; ++i)
            if (__builtin_popcount(i) == k) ans += nums[i];
        return ans;
    }
};
// java
class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int ans = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (Integer.bitCount(i) == k) ans += nums.get(i);
            // n = n & (n - 1)
        }
        return ans;
    }
}

// python
class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(x for i, x in enumerate(nums) if i.bit_count() == k)
// go
func sumIndicesWithKSetBits(nums []int, k int) (ans int) {
    for i, x := range nums {
        if bits.OnesCount(uint(i)) == k {
            ans += x
        }
    }
    return
}