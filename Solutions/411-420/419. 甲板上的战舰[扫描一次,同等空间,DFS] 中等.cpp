/*
** Problem: https://leetcode-cn.com/problems/battleships-in-a-board/
** Article: https://memcpy0.blog.csdn.net/article/details/122033533
** Author: memcpy0
*/
class Solution {
private:
    vector<bool> vis;
    int m, n;
    void dfs(vector<vector<char>>& b, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || b[x][y] == '.' || vis[x * n + y]) return;
        vis[x * n + y] = true;
        dfs(b, x + 1, y);
        dfs(b, x - 1, y);
        dfs(b, x, y + 1);
        dfs(b, x, y - 1);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        vis.resize(m * n);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !vis[i * n + j]) {
                    dfs(board, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};