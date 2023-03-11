/*
** Problem: https://leetcode.cn/problems/make-sum-divisible-by-p/
** Article: https://memcpy0.blog.csdn.net/article/details/108740518
** Author: memcpy0
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) sum = (sum + nums[i]) % p;  
        if (sum % p == 0) return 0; //整个正整数数组的和已经可以被p整除

        int ansLen = -1, now = 0; //最短子数组的长度
        unordered_map<int, int> record;
        record[0] = 0;
        //如果sum % p == x, 那么移除的子数组之和t应该满足t % p == x
        //(sum % p - t % p) % p = 0 ==> sum % p = t % p
        for (int i = 0; i < n; ++i) {
            now = (now + nums[i]) % p; //此处前缀和 % p == now
            //如果有一个前缀和 %p == (now - x) % p, 那么存在子数组 %p == x
            int last = (now - sum + p) % p; //+p,防止now-sum为负数,出现取余和取模的不一致
            unordered_map<int, int>::iterator it = record.find(last);
            if (it != record.end()) 
                if (ansLen == -1 || i + 1 - it->second < ansLen) 
                    ansLen = i + 1 - it->second; //更新最短子数组的长度
            record[now] = i + 1; //记录前缀和和这一前缀和的数组长度
        }
        if (ansLen == n) return -1; //不可以移除整个数组
        return ansLen;
    }
}; 