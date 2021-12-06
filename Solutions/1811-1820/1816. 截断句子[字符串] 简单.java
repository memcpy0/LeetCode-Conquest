/*
** Problem: https://leetcode-cn.com/problems/truncate-sentence/
** Article: https://memcpy0.blog.csdn.net/article/details/121747086
** Author: memcpy0
*/
class Solution {
    public String truncateSentence(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        for (int i = 0, n = s.length(); i < n && cnt < k; ++i) {
            char c = s.charAt(i);
            if (c == ' ') ++cnt;
            if (cnt < k) sb.append(c);
        }
        return sb.toString();
    }
}