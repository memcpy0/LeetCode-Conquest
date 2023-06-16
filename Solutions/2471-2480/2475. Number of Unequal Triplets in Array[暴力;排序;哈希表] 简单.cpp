/*
** Problem: https://leetcode.cn/problems/number-of-unequal-triplets-in-array
** Article: https://memcpy0.blog.csdn.net/article/details/131247271
** Author: memcpy0
*/
// 哈希表
class Solution {
    public int unequalTriplets(int[] nums) {
        int[] count = new int[1001];
        for (int i : nums) ++count[i];
        int a = 0, b = 0, c = nums.length;
        int ans = 0;
        for (int i = 1; i <= 1000; ++i) {
            if (count[i] != 0) {
                c -= count[i];
                ans += a * count[i] * c;
                a += count[i];
            }
        }
        return ans;
    }
}

// 排序+分组统计
class Solution {
    public int unequalTriplets(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, start = 0;
        for (int i = 0; i + 1 < nums.length; ++i) {
            if (nums[i] != nums[i + 1]) { // 到一段的末尾
                ans += start * (i - start + 1) * (nums.length - 1 - i);
                start = i + 1;
            }
        } 
        return ans;
    }
}

// 暴力循环
class Solution {
    public int unequalTriplets(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; ++i)
            for (int j = i + 1; j < nums.length; ++j)
                for (int k = j + 1; k < nums.length; ++k)
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) ++ans;
        return ans;
    }
}