/*
** Problem: https://leetcode.cn/problems/find-the-pivot-integer
** Article: https://memcpy0.blog.csdn.net/article/details/131521549
** Author: memcpy0
*/
// BEST: 数学
class Solution {
public:
    int pivotInteger(int n) {
        int m = n * (n + 1) / 2;
        int x = sqrt(m);
        return x * x == m ? x : -1;
    }
};
// 查表
class Solution {
    const unordered_map<int, int> m{{1, 1}, {8, 6}, {49, 35}, {288, 204}};
public:
    int pivotInteger(int n) {
        auto it = m.find(n);
        return it != m.end() ? it->second : -1;
    }
};
// 前缀和
class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0, tot = n * (n + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            sum += i;
            if (sum == tot - sum + i) return i;
        }
        return -1;
    }
};
// 枚举
class Solution {
public:
    int pivotInteger(int n) {
        for (int x = 1; x <= n; ++x)
            if ((1 + x) * x == (x + n) * (n - x + 1))
                return x;
        return -1;
    }
};