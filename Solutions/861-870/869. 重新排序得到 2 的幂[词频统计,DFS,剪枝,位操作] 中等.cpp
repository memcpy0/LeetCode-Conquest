/*
** Problem: https://leetcode-cn.com/problems/reordered-power-of-2/
** Article: https://memcpy0.blog.csdn.net/article/details/121026490
** Author: memcpy0
*/
class Solution {
private:
    int m = 0, cnts[10] = {0}; // m:n的位数
    bool dfs(int k, int cur) {
        if (k >= m) return !(cur & (cur - 1)); // 判断是否为2的幂
        for (int i = 0; i < 10; ++i) {
            if (cnts[i]) {
                --cnts[i];
                if ((i || cur) && dfs(k + 1, cur * 10 + i)) // 前导数字不为0
                    return true;
                ++cnts[i];
            }
        }
        return false;
    }
public:
    bool reorderedPowerOf2(int n) {
        while (n) {
            ++cnts[n % 10]; // 数位统计
            n /= 10;
            ++m; // 计算n的位数
        }
        return dfs(0, 0);
    }
};