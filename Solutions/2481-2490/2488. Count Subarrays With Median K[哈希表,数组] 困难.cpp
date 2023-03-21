/*
** Problem: https://leetcode.cn/problems/count-subarrays-with-median-k/
** Article: https://memcpy0.blog.csdn.net/article/details/129697704
** Author: memcpy0
*/
/*
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), kpos = find(nums.begin(), nums.end(), k) - nums.begin();
        // i=pos时x是0,直接记到cnt中,这样下面不是大于k就是小于k
        unordered_map<int, int> cnt;  
        cnt[0] = 1;
        for (int i = kpos - 1, x = 0; i >= 0; --i) { // 从pos-1开始累加k
            x += nums[i] < k ? 1 : -1;
            ++cnt[x]; 
        }
        // i=pos时x是0,直接加到答案中,这样下面不是大于k就是小于k
        int ans = cnt[0] + cnt[-1]; // cnt[0]=1,就是k本身
        for (int i = kpos + 1, x = 0; i < n; ++i) { // 从pos+1开始累加x
            x += nums[i] > k ? 1 : -1;
            ans += cnt[x] + cnt[x - 1];
        }
        return ans;
    }
}; 
*/
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), kpos = find(nums.begin(), nums.end(), k) - nums.begin();
        // i=pos时x是n,直接记到cnt中,这样下面不是大于k就是小于k 
        int cnt[2 * n];
        memset(cnt, 0, sizeof(cnt));
        cnt[n] = 1;
        for (int i = kpos - 1, x = n; i >= 0; --i) { // 从pos-1开始累加k
            x += nums[i] < k ? 1 : -1;
            ++cnt[x]; 
        }
        // i=pos时x是n,直接加到答案中,这样下面不是大于k就是小于k
        int ans = cnt[n] + cnt[n - 1]; // cnt[n]=1,就是k本身
        for (int i = kpos + 1, x = n; i < n; ++i) { // 从pos+1开始累加x
            x += nums[i] > k ? 1 : -1;
            ans += cnt[x] + cnt[x - 1];
        }
        return ans;
    }
}; 