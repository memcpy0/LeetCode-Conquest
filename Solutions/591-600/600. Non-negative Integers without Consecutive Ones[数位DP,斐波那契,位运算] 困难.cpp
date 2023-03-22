/*
** Problem: https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones
** Article: https://memcpy0.blog.csdn.net/article/details/117888925
** Author: memcpy0
*/
class Solution {
public:
    int findIntegers(int n) {
        int dp[32] = {1, 2}; // dp[i]:长度为i的二进制字符串中不存在连续1的字符串个数
        // =当前位为0且长度为i-1的个数+当前位为1且长度为i-2的个数(根据情况参考已求出的答案)
        for (int i = 2; i < 32; ++i) dp[i] = dp[i - 1] + dp[i - 2];
        int ans = !(n & (n >> 1)); // 如果n不存在连续1,则n&(n>>1)=0,是答案之
        for (int i = std::__lg(n); i >= 0; --i) {
            if (n >> i & 1) {
                ans += dp[i];
                if (i && n >> (i - 1) & 1) { ans += dp[i - 1]; break; }
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    int findIntegers(int n) {
        int m = std::__lg(n), dp[m + 1][2][2]; // __lg返回最高位1在第几位
        memset(dp, -1, sizeof(dp)); // lead为true表示前一位填1,否则是0 
        function<int(int, bool, bool)> f = [&](int i, bool lead, bool isLimit) -> int {
            if (i < 0) return 1;
            if (dp[i][lead][isLimit] != -1) return dp[i][lead][isLimit];
            int up = isLimit ? (n >> i & 1) : 1;  
            // 前面没填数字就相当于填了0,这里也可填0
            int ans = f(i - 1, false, isLimit && up == 0); // 一开始的isLimit是true,n>>i&1是1
            if (!lead && up == 1) ans += f(i - 1, true, isLimit); // 还可填1
            return dp[i][lead][isLimit] = ans;
        };
        return f(m, false, true); // i从m往小枚举，方便位运算
    }
};
*/

/*
class Solution {
public:
    int findIntegers(int n) {
       int m = std::__lg(n), dp[m + 1][2][2][2]; // __lg返回最高位1在第几位
        memset(dp, -1, sizeof(dp)); // lead为true表示前一位填1,否则是0
        function<int(int, bool, bool, bool)> f = [&](int i, bool lead, bool isNum, bool isLimit) -> int {
            if (i < 0) return 1;
            if (dp[i][lead][isNum][isLimit] != -1) return dp[i][lead][isNum][isLimit];
            int ans = 0;
            if (!isNum) { // 没填数字,可填0或1
                ans += f(i - 1, false, false, false); // 不填
                if (!isLimit || (n >> i & 1)) ans += f(i - 1, true, true, isLimit); // 能填1
            } else {
                ans += f(i - 1, false, true, isLimit && !(n >> i & 1)); // 无论是否受到限制都可填0
                if (!lead && (!isLimit || (n >> i & 1))) ans += f(i - 1, true, true, isLimit);
            }
            return dp[i][lead][isNum][isLimit] = ans;
        };
        return f(m, false, false, true); // i从m往小枚举，方便位运算
    }
};
*/