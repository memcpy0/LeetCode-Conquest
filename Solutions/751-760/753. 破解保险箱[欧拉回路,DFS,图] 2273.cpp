/*
** Problem: https://leetcode.cn/problems/cracking-the-safe
** Article: https://memcpy0.blog.csdn.net/article/details/132948696
** Author: memcpy0
*/
// BEST: 使用int存储,更省空间
class Solution {
private:
    int highest, k;
    string ans;
    unordered_set<int> rec;
    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int nei = node * 10 + x;
            if (!rec.count(nei)) { // 改为插入边
                rec.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        this->highest = pow(10, n - 1);
        this->k = k;
        dfs(0); // 从n-1个0出发
        ans += string(n - 1, '0'); // 返回的路径顺序应该是n-1个0+翻转的ans
        // 由于是欧拉回路,所以不用翻转,即可直接返回
        return ans;
    }
};
// 更好理解
class Solution {
private:
    string ans;
    unordered_set<string> edges;
    void dfs(string &cur, int k) {
        for (int i = 0; i < k; ++i) {
            string edge = cur + to_string(i);
            if (!edges.count(edge)) {
                edges.insert(edge);
                string next = edge.substr(1);
                dfs(next, k);
                ans += to_string(i);
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        string start = string(n - 1, '0');
        dfs(start, k);
        ans += start;
        return ans;
    }
};