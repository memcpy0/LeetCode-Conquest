/*
** Problem: https://leetcode.cn/problems/collecting-chocolates/
** Article: https://memcpy0.blog.csdn.net/article/details/135281219
** Author: memcpy0
*/
给你一个长度为 `n` 、下标从 **0** 开始的整数数组 `nums` ，表示收集不同巧克力的成本。每个巧克力都对应一个不同的类型，最初，位于下标 `i` 的巧克力就对应第 `i` 个类型。

在一步操作中，你可以用成本 `x` 执行下述行为：
- 同时修改所有巧克力的类型，将巧克力的类型 `ith` 修改为类型 `((i + 1) mod n)th`。

假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。

**示例 1：**
```cpp
输入：nums = [20,1,15], x = 5
输出：13
解释：最开始，巧克力的类型分别是 [0,1,2] 。我们可以用成本 1 购买第 1 个类型的巧克力。
接着，我们用成本 5 执行一次操作，巧克力的类型变更为 [1,2,0] 。我们可以用成本 1 购买第 2 个类型的巧克力。
然后，我们用成本 5 执行一次操作，巧克力的类型变更为 [2,0,1] 。我们可以用成本 1 购买第 0 个类型的巧克力。
因此，收集所有类型的巧克力需要的总成本是 (1 + 5 + 1 + 5 + 1) = 13 。可以证明这是一种最优方案。
```
**示例 2：**
```cpp
输入：nums = [1,2,3], x = 4
输出：6
解释：我们将会按最初的成本收集全部三个类型的巧克力，而不需执行任何操作。因此，收集所有类型的巧克力需要的总成本是 1 + 2 + 3 = 6 。
```
**提示：**
- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^9`
- `1 <= x <= 10^9`

// cpp
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> s(n); // s[k] 统计操作 k 次的总成本
        for (int i = 0; i < n; ++i)
            s[i] = (long long) i * x;
        for (int i = 0; i < n; ++i) { // 子数组左端点
            int mn = nums[i];
            for (int j = i; j < n + i; ++j) { // 子数组右端点（把数组看做环状）
                mn = min(mn, nums[j % n]); // 维护nums[i : j]的最小值
                s[j - i] += mn; // 累加操作 j-i 次时的成本
            }
        }
        return *min_element(s.begin(), s.end());
    }
};

// java
class Solution {
    public long minCost(int[] nums, int x) {
        int n = nums.length;
        long[] s = new long[n];
        for (int i = 0; i < n; ++i) 
            s[i] = (long) i * x;
        for (int i = 0; i < n; ++i) {
            int mn = nums[i];
            for (int j = i; j < n + i; ++j) {
                mn = Math.min(mn, nums[j % n]);
                s[j - i] += mn;
            }
        }
        long ans = Long.MAX_VALUE;
        for (long v : s) ans = Math.min(ans, v);
        return ans;
    }
}

// go
func minCost(nums []int, x int) int64 {
    n := len(nums)
    s := make([]int64, n)
    for i := range s {
        s[i] = int64(i) * int64(x)
    }
    for i, mn := range nums {
        for j := i; j < n + i; j++ {
            mn = min(mn, nums[j % n]);
            s[j - i] += int64(mn);
        }
    }
    return slices.Min(s)
}

// rust
impl Solution {
    pub fn min_cost(nums: Vec<i32>, x: i32) -> i64 {
        let n = nums.len();
        let mut s: Vec<i64> = (0..n).map(|i| i as i64 * x as i64).collect();
        for i in 0..n {
            let mut mn = nums[i];
            for j in i..(n + i) {
                mn = mn.min(nums[j % n]);
                s[j - i] += mn as i64;
            }
        }
        *s.iter().min().unwrap()
    }
}

// python
class Solution:
    def minCost(self, nums: List[int], x: int) -> int:
        n = len(nums)
        s = list(range(0, n * x, x))
        for i, mn in enumerate(nums):
            for j in range(i, n + i):
                mn = min(mn, nums[j % n])
                s[j - i] += mn
        return min(s)