/*
** Problem: https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
** Article: https://memcpy0.blog.csdn.net/article/details/129466606
** Author: memcpy0
*/
/*
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = blocks.size();
        for (int i = 0, n = blocks.size(); i + k <= n; ++i) {
            int op = 0;
            for (int j = 0; j < k; ++j) 
                if (blocks[i + j] == 'W') ++op;
            ans = min(ans, op);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), partial_sum[n + 1];
        memset(partial_sum, 0, sizeof(partial_sum)); 
        for (int i = 1; i <= k; ++i)
            partial_sum[i] = partial_sum[i - 1] + (blocks[i - 1] == 'W'); 
        int ans = partial_sum[k];
        for (int i = k + 1; i <= n; ++i) {
            partial_sum[i] = partial_sum[i - 1] + (blocks[i - 1] == 'W'); 
            ans = min(ans, partial_sum[i] - partial_sum[i - k]);
        }
        return ans;
    }
};