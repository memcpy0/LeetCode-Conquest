/*
** Problem: https://leetcode.cn/problems/counting-bits/
** Article: https://memcpy0.blog.csdn.net/article/details/132680516
** Author: memcpy0
*/
// BEST: 去除最低设置位
class Solution {
    public int[] countBits(int n) {
        int[] bits = new int[n + 1];
        for (int i = 1; i <= n; i++)
            bits[i] = bits[i & (i - 1)] + 1;
        return bits;
    }
}
// 去除最低有效位(0或1)
class Solution {
    public int[] countBits(int n) {
        int[] bits = new int[n + 1];
        for (int i = 1; i <= n; i++)
            bits[i] = bits[i >> 1] + (i & 1);
        return bits;
    }
}
// 去除最高有效位
class Solution {
    public int[] countBits(int n) {
        int[] bits = new int[n + 1];
        int highBit = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) highBit = i;
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
}
// 朴素算法: O(nlogn)
class Solution {
    public int[] countBits(int n) {
        int[] bits = new int[n + 1];
        for (int i = 0; i <= n; i++) bits[i] = countOnes(i);
        return bits;
    }
    public int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }
}