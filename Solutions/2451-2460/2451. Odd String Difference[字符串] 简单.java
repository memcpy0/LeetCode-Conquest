/*
** Problem: https://leetcode.cn/problems/odd-string-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/130877321
** Author: memcpy0
*/
class Solution {
    public String oddString(String[] words) {
        int n = words[0].length();
        for (int i = 1; i < n; ++i) {
            int d = words[0].charAt(i) - words[0].charAt(i - 1);
            int idx = 0, cnt = 0;
            for (int j = 1; j < words.length; ++j) {
                int td = words[j].charAt(i) - words[j].charAt(i - 1);
                if (td != d) {
                    idx = j;
                    ++cnt;
                } 
            }
            if (cnt == 0) continue;
            if (cnt == words.length - 1) return words[0];
            return words[idx];
        }
        return "";
    }
}