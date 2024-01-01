/*
** Problem:https://leetcode.cn/problems/string-compression-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/135326873
** Author: memcpy0
*/
// cpp
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        auto calc = [](int x) {
            if (x == 1) return 1;
            if (x < 10) return 2;
            if (x < 100) return 3;
            return 4;
        };
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX >> 1));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k && j <= i; ++j) { // 删除j个字符
                // 删除0个字符时要保留s[i-1]
                // 删除多个字符时考虑删除第i个字符和不删除第i个字符的情况
                if (j > 0) f[i][j] = f[i - 1][j - 1]; // 删除s[i-1]这个字符
                int same = 0, diff = 0; // diff统计不同的字符,都是要删除的
                for (int i0 = i; i0 >= 1 && diff <= j; --i0) { // diff<=j
                    if (s[i0 - 1] == s[i - 1]) {
                        ++same; // 删除[i0-1,i-1]中间的不同字符
                        f[i][j] = min(f[i][j], f[i0 - 1][j - diff] + calc(same));
                    } else {
                        ++diff;
                    }
                }
            }
        }
        return f[n][k];
    }
};

// java
class Solution {
    private int calc(int x) {
        if (x == 1) return 1;
        if (x < 10) return 2;
        if (x < 100) return 3;
        return 4;
    }
    public int getLengthOfOptimalCompression(String s, int k) {
        int n = s.length();
        int[][] f = new int[n + 1][k + 1];
        for (int i = 0; i <= n; ++i) {
            Arrays.fill(f[i], Integer.MAX_VALUE >> 1);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k && j <= i; ++j) {
                if (j > 0) f[i][j] = f[i - 1][j - 1];
                int same = 0, diff = 0;
                for (int i0 = i; i0 >= 1 && diff <= j; --i0) {
                    if (s.charAt(i0 - 1) == s.charAt(i - 1)) {
                        ++same;
                        f[i][j] = Math.min(f[i][j], f[i0 - 1][j - diff] + calc(same));
                    } else ++diff;
                }
            }
        }
        return f[n][k];
    }
}

// python
class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        calc = lambda x : 1 if x == 1 else (2 if x < 10 else (3 if x < 100 else 4))

        n = len(s)
        f = [ [10**9] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 0

        for i in range(1, n + 1):
            for j in range(min(k, i) + 1):
                if j > 0:
                    f[i][j] = f[i - 1][j - 1]
                same = diff = 0
                for i0 in range(i, 0, -1):
                    if s[i0 - 1] == s[i - 1]:
                        same += 1
                        f[i][j] = min(f[i][j], f[i0 - 1][j - diff] + calc(same))
                    else:
                        diff += 1
                        if diff > j:
                            break
        return f[n][k]