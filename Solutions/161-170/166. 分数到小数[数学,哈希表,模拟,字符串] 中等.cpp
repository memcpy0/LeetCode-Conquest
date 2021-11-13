/*
** Problem: https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
** Article: https://memcpy0.blog.csdn.net/article/details/121299458
** Author: memcpy0
*/
class Solution {
public:
    using ll = long long;
    string fractionToDecimal(int numerator , int denominator) {
        ll n = numerator, d = denominator, idx = 0; // 防止溢出
        if (n % d == 0) return to_string(n / d); // 如果能够整除,直接返回计算结果,可能为负数
        string ans, tmp;
        if (n * d < 0) ans.push_back('-'); // 如果其一为负数,先追加负号
        n = abs(n), d = abs(d); // 都化为非负整数,方便计算
        ans += to_string(n / d) + "."; // 计算整数部分,并将余数赋值给n
        n %= d; // 此时0<n<d
        unordered_map<ll, ll> rec;
        do { 
            rec[n] = idx++; // 记录当前余数对应的(小数点后第几位)位置,可能从该位开始循环
            n *= 10; // 在余数后补零
            tmp.push_back('0' + n / d); // n/d可能为零或其他数位
            n %= d;
        } while (n && rec.find(n) == rec.end()); // 当余数n不等于0、且n未出现过时,继续循环
        if (n) { // 如果当前余数之前出现过
            int pos = rec[n];
            for (int i = 0, n = tmp.size(); i < n; ++i) {
                if (i == pos) ans.push_back('(');
                ans.push_back(tmp[i]);
            }
            ans.push_back(')');
        } else ans += tmp;
        return ans;
    }
};