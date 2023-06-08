/*
** Problem: https://leetcode.cn/problems/equal-row-and-column-pairs/
** Article: https://memcpy0.blog.csdn.net/article/details/131105914
** Author: memcpy0
*/
// 前缀树
class Solution {
private:
    class Trie {
    public: 
        int endNum; // 记录以此为终结点的数组的个数
        Trie() : endNum(0) {}
        unordered_map<int, Trie*> children;    
    };
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        Trie* root = new Trie;
        Trie* cur = root;
        for (int i = 0; i < n; ++i) {
            cur = root;
            for (int j = 0; j < n; ++j) {
                if (!cur->children[grid[i][j]])
                    cur->children[grid[i][j]] = new Trie;
                cur = cur->children[grid[i][j]];
            }
            ++cur->endNum;
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            cur = root;
            for (int i = 0; i < n; ++i) {
                if (cur->children[grid[i][j]])
                    cur = cur->children[grid[i][j]];
                else break;
            }
            ans += cur->endNum;
        }
        return ans;
    }
};

// 模拟
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) { // 每次将第i行比较第j列
                int ok = 1;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) { // 第i行第k列等于第j列第k行
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};