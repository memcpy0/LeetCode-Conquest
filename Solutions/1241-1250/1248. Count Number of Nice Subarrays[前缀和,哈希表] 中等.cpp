/*
** Problem: https://leetcode.cn/problems/count-number-of-nice-subarrays/
** Article: https://memcpy0.blog.csdn.net/article/details/131310520
** Author: memcpy0
*/
// 数学
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        int odd[n + 2], cnt = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i] & 1) odd[++cnt] = i; // 记录第cnt个奇数的下标
        odd[0] = -1, odd[++cnt] = n; // 两个哨兵
        for (int i = 1; i + k <= cnt; ++i) // cnt已经加了1
            ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
        return ans;
    }
};
// BEST: 快慢指针+滑动窗口
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        int left = 0, right = 0, oddCnt = 0;
        while (right < n) {
            // 右指针先走,每遇到一个奇数则+1
            if (nums[right++] & 1) ++oddCnt;
            // 若当前滑动窗口[left,right)有k个奇数,进入此分支统计当前滑动窗口中优美子数组个数
            if (oddCnt == k) {
                // 先将滑动窗口右边界向右拓展,直到遇到下个奇数(或出界)
                // rightEvenCnt即为第k个奇数右边的偶数个数
                int tmp = right;
                while (right < n && (nums[right] & 1) == 0) ++right;
                int rightEvenCnt = right - tmp;
                // leftEventCnt即为第1个奇数左边的偶数个数
                int leftEventCnt = 0;
                while ((nums[left] & 1) == 0) {
                    ++leftEventCnt;
                    ++left;
                }
                // 第1个奇数左边的leftEvenCnt个偶数都可作为优美子数组的起点
                // 因为第1个奇数左边可1个偶数都不取,所以起点的选择有leftEvenCnt + 1 种）
                // 第k个奇数右边的rightEvenCnt个偶数都可作为优美子数组的终点
                // 因为第k个奇数右边可以1个偶数都不取,所以终点的选择有 rightEvenCnt + 1 种）
                // 所以该滑动窗口中,优美子数组左右起点的选择组合数为(leftEvenCnt + 1)*(rightEvenCnt + 1) 
                ans += (leftEventCnt + 1) * (rightEvenCnt + 1);
                // 此时left指向的是第1个奇数,因为该区间已经统计完了,因此left右移一位,oddCnt--
                ++left;
                --oddCnt;
            }
        }
        return ans;
    }
};
// 前缀和+哈希表/频次数组
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        // unordered_map<int, int> rec;
        int rec[n + 1];
        memset(rec, 0, sizeof(rec));
        rec[0] = 1;
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] & 1);
            ans += sum >= k ? rec[sum - k] : 0;
            ++rec[sum];
        }
        return ans;
    }
};