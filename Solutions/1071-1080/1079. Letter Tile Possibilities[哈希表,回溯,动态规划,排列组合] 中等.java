/*
** Problem: https://leetcode.cn/problems/letter-tile-possibilities
** Article: https://memcpy0.blog.csdn.net/article/details/130767997
** Author: memcpy0
*/
// O(n^2) 动态规划
class Solution {
    private static final int MX = 8;
    private static final int[][] c = new int[MX][MX];
    static {
        for (int i = 0; i < MX; ++i) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; ++j)
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; // 预处理组合数
        }
    } 
    public int numTilePossibilities(String tiles) {
        // 改成 int[26] 统计可能会快一点点，感兴趣可以试试（下面 DP 跳过 cnt=0 的情况）
        var counts = new HashMap<Character, Integer>(); // 统计每个字母的出现次数
        for (var c : tiles.toCharArray())
            counts.merge(c, 1, Integer::sum); // counts[c]++
        var f = new int[tiles.length() + 1];
        f[0] = 1; // 构造空序列的方案数
        int n = 0;
        for (var cnt : counts.values()) { // 枚举第i种字母
            n += cnt; // 常数优化：相比从 tiles.length() 开始要更快
            for (int j = n; j > 0; --j)  // 枚举序列长度j
                // 枚举第i种字母选了k个，注意k=0时的方案数已经在f[j]中了
                for (int k = 1; k <= j && k <= cnt; ++k)
                    f[j] += f[j - k] * c[j][k];
        }
        int ans = 0;
        for (int j = 1; j <= n; ++j) ans += f[j];
        return ans;
    }
}

class Solution {
    private static final int MX = 8;
    private static final int[][] c = new int[MX][MX];
    static {
        for (int i = 0; i < MX; ++i) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; // 预处理组合数
            }
        }
    } 
    public int numTilePossibilities(String tiles) {
        var counts = new HashMap<Character, Integer>(); // 统计每个字母的出现次数
        for (var c : tiles.toCharArray())
            counts.merge(c, 1, Integer::sum); // counts[c]++
        int m = counts.size(), n = tiles.length();
        var f = new int[m + 1][n + 1]; // 以前i种字母构造j长序列的方案数
        f[0][0] = 1; // 构造空序列的方案数
        int i = 1; 
        for (var cnt : counts.values()) { // 枚举第i种字母
            for (int j = 0; j <= n; ++j) // 枚举序列长度
                for (int k = 0; k <= j && k <= cnt; ++k) // 枚举第i种字母选了k个
                    f[i][j] += f[i - 1][j - k] * c[j][k];
                
            ++i;
        }
        int ans = 0;
        for (int j = 1; j <= n; ++j) ans += f[m][j];
        return ans;
    }
}

/* 回溯+排列+子集生成
class Solution {
private:
    int ans = 0;
    unordered_set<string> rec;
    void dfs(string& s, string& t, int b, int e) {
        if (b >= e) {
            string f = t;
            if (f.empty()) return; 
            sort(f.begin(), f.end()); 
            do { 
                if (rec.find(f) == rec.end()) {
                    ++ans;
                    rec.insert(f);
                }
            } while (next_permutation(f.begin(), f.end()));
            return ;
        } 
        dfs(s, t, b + 1, e);
        t.push_back(s[b]); 
        dfs(s, t, b + 1, e); 
        t.pop_back(); 
    }
public:
    int numTilePossibilities(string tiles) {
        string s;
        dfs(tiles, s, 0, tiles.size());
        return ans;
    }
};  
*/