/*
** Problem: https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/
** Article: https://memcpy0.blog.csdn.net/article/details/130660313
** Author: memcpy0
*/
class Solution {
    public boolean queryString(String s, int n) {
        if (n == 1) return s.contains("1");
        int k = 31 - Integer.numberOfLeadingZeros(n); // n的二进制长度减一
        if (s.length() < Math.max(n - (1 << k) + k + 1, (1 << (k - 1)) + k - 1)) return false;    
        return check(s, k, n / 2 + 1, (1 << k) - 1) && check(s, k + 1, 1 << k, n);
    }
    // 对于长为k的在[lower, upper]的内的二进制数，判断这些数s是否都有
    private boolean check(String s, int k, int lower, int upper) {
        if (lower > upper) return true;
        var seen = new HashSet<Integer>();
        int mask = (1 << (k - 1)) - 1; // k>=1
        int x = Integer.parseInt(s.substring(0, k - 1), 2); // 按二进制获取值
        for (int i = k - 1, m = s.length(); i < m; ++i) {
            // & mask可以去掉最高比特位，从而实现滑窗的「出」
            // << 1 || (s.charAt(i) - '0') 即为滑窗的「入」
            x = ((x & mask) << 1) | (s.charAt(i) - '0');
            if (lower <= x && x <= upper) seen.add(x);
        }
        return seen.size() == upper - lower + 1;
    }
}

/*
class Solution {
    public boolean queryString(String S, int n) {
        var seen = new HashSet<Integer>();
        var s = S.toCharArray();
        for (int i = 0, m = s.length; i < m; ++i) {
            int x = s[i] - '0';
            if (x == 0) continue; // 二进制数从1开始
            for (int j = i + 1; x <= n; ++j) {
                seen.add(x);
                if (j == m) break;
                x = (x << 1) | (s[j] - '0'); // 子串[i,j]的二进制数
            }
        }
        return seen.size() == n;
    }
}
*/

/*
class Solution {
    public boolean queryString(String s, int n) {
        for (int i = 1; i <= n; ++i)
            if (!s.contains(Integer.toBinaryString(i)))
                return false; 
        return true;
    }
}
*/