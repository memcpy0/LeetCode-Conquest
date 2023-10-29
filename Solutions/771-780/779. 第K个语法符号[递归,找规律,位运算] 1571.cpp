/*
** Problem: https://leetcode.cn/problems/k-th-symbol-in-grammar/
** Article: https://memcpy0.blog.csdn.net/article/details/134107460
** Author: memcpy0
*/
// 递归
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        return (k & 1) ^ 1 ^ kthGrammar(n - 1, (k + 1) / 2);
    }
};
// 找规律+递归
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1) return 0; 
        // 查询某一个行第k数，如果k在后半部分，可转化为求解该行前半部分对应位置的翻转数字
        if (k > (1 << (n - 2))) return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2))); 
        return kthGrammar(n - 1, k); // 一行前半部分和上一行相同
    }
};
// BEST
class Solution {
public:
    int kthGrammar(int n, int k) {
        // return __builtin_popcount(k - 1) & 1;
        k--;
        int res = 0;
        while (k > 0) {
            k &= k - 1;
            res ^= 1;
        }
        return res;
    }
};