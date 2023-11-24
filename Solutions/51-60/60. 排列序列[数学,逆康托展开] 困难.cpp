/*
** Problem: https://leetcode.cn/problems/permutation-sequence
** Article: https://memcpy0.blog.csdn.net/article/details/134609466
** Author: memcpy0
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
        int factory[10] = {1};
        for (int i = 1; i < n; ++i) factory[i] = factory[i - 1] * i;
        bool vis[10] = {false};

        string ans;
        for (int i = n - 1; i >= 0; --i) {
            int num = k / factory[i];
            k = k % factory[i];
            for (int j = 1; j <= n; ++j) {
                if (!vis[j]) {
                    if (num-- == 0) {
                        ans += '0' + j;
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};