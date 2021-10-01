/*
** Problem: https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/
** Article: https://memcpy0.blog.csdn.net/article/details/108908349
** Author: memcpy0
*/
class Solution {
private:
    char hex[17] = "0123456789abcdef";
public:
    string toHex(int num) {
        string ans;
        uint32_t n = static_cast<uint32_t>(num);
        do {
            ans.push_back(hex[n & 0xf]);
            n >>= 4;
        } while (n);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};