/*
** Problem: https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/
** Article: https://memcpy0.blog.csdn.net/article/details/129937095
** Author: memcpy0
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt[101];
        memset(cnt, 0, sizeof(cnt));
        for (int num : nums) ++cnt[num]; // 桶排序
        int step = 0, sum = 0;
        for (int m = 1; m <= 100; ++m) {
            if (cnt[m]) { // 每个遍历到的非零元素,都是此时数组中最小非零元素
                if (sum == 0) { // sum记录已经减去的值之和
                    sum = m; // 将数组中每个非零元素都减去m
                    ++step; // 操作数+1
                } else {
                    if (m - sum != 0) ++step; // 如果该元素没有被减为零,则要减去自己,操作数+1
                    sum += m - sum;
                }
            }
        }
        return step;
    }
};