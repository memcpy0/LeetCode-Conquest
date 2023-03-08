/*
** Problem: https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/
** Article: https://memcpy0.blog.csdn.net/article/details/129405037
** Author: memcpy0
*/

/*
class Solution {
    public int minimumDeletions(String s) {
        int a = 0, ta = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            if (s.charAt(i) == 'a') ++a;
        int minDel = a; // 以下标0之前作为a,b分割线,要删除全部a
        for (int i = 0; i < n; ++i) { // 以下标i之后作为分割线
            if (s.charAt(i) == 'a') ++ta;
            int bComeBeforeA = i + 1 - ta;
            // ta bComeBeforeA | a-ta n-a-bComeBeforeA
            // 删除前面的bComeBeforeA个b和后面的a-ta个a
            minDel = Math.min(minDel, bComeBeforeA + a - ta);
        }
        return minDel;
    }
}
*/
class Solution {
    public int minimumDeletions(String s) {
        int del = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            del += ('b' - s.charAt(i));
        int ans = del;
        for (int i = 0; i < n; ++i) { // 以下标i之后作为分割线
            del += (s.charAt(i) - 'a') * 2 - 1; // 'a':-1,'b':1
            ans = Math.min(del, ans);
        }
        return ans;
    }
}