/*
** Problem: https://leetcode-cn.com/problems/bulls-and-cows/
** Article: https://memcpy0.blog.csdn.net/article/details/121216063
** Author: memcpy0
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        int a = 0, b = 0, cnt[10] = {0};
        for (int i = 0, n = secret.size(); i < n; ++i) {
            if (secret[i] == guess[i]) ++a;
            else {
                if (cnt[guess[i] - '0']-- > 0) ++b;
                if (cnt[secret[i] - '0']++ < 0) ++b;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};