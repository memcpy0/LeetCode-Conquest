/*
** Problem: https://leetcode-cn.com/problems/to-lower-case/
** Article: https://memcpy0.blog.csdn.net/article/details/107632888
** Author: memcpy0
*/
class Solution {
    public String toLowerCase(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c >= 'A' && c <= 'Z') sb.append((char)(c + 32));
            else sb.append(c);
        }
        return sb.toString();
    }
}