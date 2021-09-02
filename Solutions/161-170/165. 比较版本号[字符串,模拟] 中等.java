/*
** Problem: https://leetcode-cn.com/problems/compare-version-numbers/
** Article: https://memcpy0.blog.csdn.net/article/details/120057739
** Author: memcpy0
*/
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] a = version1.split("\\."), b = version2.split("\\.");
        for (int i = 0, j = 0, n = a.length, m = b.length; i < n || j < m; ++i, ++j) {
            int an = (i < a.length) ? Integer.parseInt(a[i]) : 0;
            int bn = (i < b.length) ? Integer.parseInt(b[i]) : 0;
            if (an != bn) return an < bn ? -1 : 1;
        }
        return 0;  
    }
}