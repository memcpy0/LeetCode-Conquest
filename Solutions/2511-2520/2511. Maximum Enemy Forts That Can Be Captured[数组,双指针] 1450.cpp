/*
** Problem: https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured
** Article: https://memcpy0.blog.csdn.net/article/details/132684672
** Author: memcpy0
*/
// BEST: 双指针+数组
class Solution {
public:
    int captureForts(vector<int> forts) {
        int ans = 0;
        int pre = -1;
        for (int i = 0; i < forts.size(); ++i) {
            if (forts[i]) {
                if (pre >= 0 && forts[i] != forts[pre]) // 一个是1，另一个是-1
                    ans = max(ans, i - pre - 1);
                pre = i;
            }
        }
        return ans;
    }
};