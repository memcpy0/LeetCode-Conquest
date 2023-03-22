/*
** Problem: https://leetcode.cn/problems/numbers-with-repeated-digits/
** Article: https://memcpy0.blog.csdn.net/article/details/129720323
** Author: memcpy0
*/
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int m = s.size(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool isNum, bool isLimit) -> int {
            if (i >= m) return isNum; // 为true表示是一个合法数字,否则不是
            if (isNum && !isLimit && dp[i][mask] != -1)
                return dp[i][mask];
            int ans = 0;
            if (!isNum) // 当前数位可以不填数字
                ans += f(i + 1, mask, false, false); // 后面不受限制了
            // 下面开始填数字
            int lower = isNum ? 0 : 1, upper = isLimit ? s[i] - '0' : 9;
            for (int d = lower; d <= upper; ++d) // 枚举要填入的数字
                if ((mask >> d & 1) == 0) // i前面没有使用,这里可用
                    ans += f(i + 1, mask | (1 << d), true, isLimit && d == upper);
            if (isNum && !isLimit)
	            dp[i][mask] = ans;
            // 当前位填数字和不填数字得到的合法方案数都考虑了
            return ans;
        };
        return n - f(0, 0, false, true);
    }
};
/*
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        // f(i,mask,isNum,isLimit)表示计算第i位及以后的合法方案数
        // 这里先计算无重复数字的正整数的个数,因此用mask表示已经使用了哪些数字
        // isNum则表示前面是否是数字,即前面填了数字没有,填了前面就是数字为true,否则前面不是数字为false
        // isLimit表示是否受到了n的约束,为true表示受到n的约束,即第i位填的数<=s[i];为false表示不受到s[i]约束,最大能填9
        // isNum为true,前面填了数字,则这里必须填数字,从0开始,看是否受到限制来填数字
        // isNum为false,前面没填数字,则这里也可不填数字,此后isNum还是false,isLimit为false(因为前面必小于s[i]前面);或者从1填起来,看是否受到限制来填数字
        // 填数字后,isNum变为true,看情况决定isLimit是否为true(现在受到限制&&填的数字是否等于s[i])
        // 如果现在不受限制,以后也不受限制;如果现在受限制,但填的数小于s[i],则后面不受限制;否则后面要受到限制
        int m = s.size(), dp[m][1 << 10][2][2];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool isNum, bool isLimit) -> int {
            if (i >= m) return isNum; // 为true表示是一个合法数字,否则不是
            if (dp[i][mask][isNum][isLimit] != -1)
                return dp[i][mask][isNum][isLimit];
            int ans = 0;
            if (!isNum) // 当前数位可以不填数字
                ans += f(i + 1, mask, false, false); // 后面不受限制了
            // 下面开始填数字
            int lower = isNum ? 0 : 1, upper = isLimit ? s[i] - '0' : 9;
            for (int d = lower; d <= upper; ++d) // 枚举要填入的数字
                if ((mask >> d & 1) == 0) // i前面没有使用,这里可用
                    ans += f(i + 1, mask | (1 << d), true, isLimit && d == upper);
            // 当前位填数字和不填数字得到的合法方案数都考虑了
            return dp[i][mask][isNum][isLimit] = ans;
        };
        return n - f(0, 0, false, true);
    }
};
*/
