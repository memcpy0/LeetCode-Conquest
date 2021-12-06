/*
** Problem: https://leetcode-cn.com/problems/super-pow/
** Article: https://memcpy0.blog.csdn.net/article/details/110154274
** Author: memcpy0
*/
class Solution {
    private int mod = 1337;
    private int fastPow(int a, int b) {
        int ans = 1;
        a %= mod; // a可能比较大,模mod后就<1337,相乘时不会溢出
        while (b != 0) {
            if ((b & 1) != 0) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    private int dfs(int a, int[] b, int i) {
        if (i == -1) return 1;
        return (fastPow(dfs(a, b, i - 1), 10) * fastPow(a, b[i])) % mod;
    }
    public int superPow(int a, int[] b) {
        return dfs(a, b, b.length - 1);
    }
}