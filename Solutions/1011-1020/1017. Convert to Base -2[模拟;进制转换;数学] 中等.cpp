/*
** Problem: https://leetcode.cn/problems/convert-to-base-2/
** Article: https://memcpy0.blog.csdn.net/article/details/130773366
** Author: memcpy0
*/
class Solution {
public:
    string baseNeg2(int n) {
        int val = 0x55555555 ^ (0x55555555 - n);
        if (val == 0) return "0";
        string ans;
        while (val) {
            ans.push_back('0' + (val & 1));
            val >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
// 进制转换
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0 || n == 1) return to_string(n);
        string ans;
        while (n) {
            // int r = abs(n % (-2));
            int r = n & 1; // r只能为0或1
            ans.push_back('0' + r);
            n = (n - r) / (-2); // 进制转换
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
*/

/*
// 模拟进位简版
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0 || n == 1) return to_string(n);
        string ans;
        for (int i = 0; n; ++i) {
            // int r = abs(n % (-2));
            int r = n & 1; // r只能为0或1
            ans.push_back('0' + r);
            if (i & 1) n += (n & 1) << 1; // 原数加上1<<(i+1)
            n >>= 1; // 继续右移,查看n的二进制表示
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 模拟进位
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        int i = 0, bits[32]{0};
        for (int i = 0; i < 32 && n != 0; ++i) {
            if (n & 1) { // n二进制表示中这一位为1
                ++bits[i];
                if (i & 1) ++bits[i + 1]; // 进位在后面处理
            }
            n >>= 1;
        } 
        int carry = 0;
        for (int i = 0; i < 32; ++i) {
            int v = carry + bits[i];
            // bits[i] = v & 1; 
            bits[i] = abs(v % (-2));
            carry = (v - bits[i]) / (-2);
        }
        int pos = 31;
        while (pos >= 0 && bits[pos] == 0) --pos;
        string ans;
        while (pos >= 0) ans.push_back(bits[pos--] + '0');
        return ans;
    }
};
*/