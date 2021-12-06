/*
** Problem: https://leetcode-cn.com/problems/super-pow/
** Article: https://memcpy0.blog.csdn.net/article/details/110154274
** Author: memcpy0
*/
class Solution {
private:
    int mod = 1337;
    int fastPow(int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a %= mod; // a可能比较大,模mod后就<1337,相乘时不会溢出
        for (int i = b.size() - 1; i >= 0; --i) {
            if (b[i] != 0) ans = (ans * fastPow(a, b[i])) % mod;
            a = fastPow(a, 10);
        }
        return ans;
    }
};