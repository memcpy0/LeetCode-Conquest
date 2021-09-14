/*
** Problem: https://leetcode-cn.com/problems/string-compression/
** Article: https://memcpy0.blog.csdn.net/article/details/119845202
** Author: memcpy0
*/
class Solution {
public:
    int compress(vector<char>& chars) { 
        int ans = 0;
        for (int i = 0, len = 1, n = chars.size(); i < n; ++i, ++len) {
            if (i + 1 != n && chars[i] == chars[i + 1]) continue;
            chars[ans++] = chars[i];
            if (len > 1) {
                int l = ans;
                while (len) {
                    chars[ans++] = '0' + len % 10;
                    len /= 10;
                }
                int r = ans - 1;
                while (l < r) swap(chars[l++], chars[r--]);
            }
            len = 0;
        } 
        return ans;
    }
}