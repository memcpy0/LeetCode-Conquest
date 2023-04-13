/*
** Problem: https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/
** Article: https://memcpy0.blog.csdn.net/article/details/130140449
** Author: memcpy0
*/
class Solution {
    public int longestDecomposition(String text) {
        int ans = 0;
        int left = 0, right = text.length() - 1;
        while (left <= right) {
            int l = left, r = right;
            while (l < r) { // 扫描从后往前的相同字符
                if (text.charAt(l) != text.charAt(r)) --r; // 继续往前找,text[l]==text[r]
                else {
                    int i = l, j = r; // [i,...] 和 [j,...]比较
                    boolean flag = true;
                    for (; i < r && j <= right; ++i, ++j) {
                        if (text.charAt(i) != text.charAt(j)) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag && j > right) {
                        ans += 2;
                        left = i;
                        right = r - 1;
                        break; // 这里出来的l一定不等于r
                    } else --r; // 接着找上一个text[r]==text[l]
                }
            }
            if (l == r) { // 说明没找到一个text[r]==text[l],这就是一个字符串
                ++ans;
                break;
            }
        }
        return ans;
    }
}