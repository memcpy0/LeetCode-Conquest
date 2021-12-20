/*
** Problem: https://leetcode-cn.com/problems/battleships-in-a-board/
** Article: https://memcpy0.blog.csdn.net/article/details/122033533
** Author: memcpy0
*/
class Solution { 
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int ans = 0;
        vector<bool> vis(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != 'X' || vis[i * n + j]) continue;
                vis[i * n + j] = true;
                for (int k = i + 1; k < m && board[k][j] == 'X'; ++k) vis[k * n + j] = true;
                for (int k = j + 1; k < n && board[i][k] == 'X'; ++k) vis[i * n + k] = true;
                ++ans;
            }
        }
        return ans;
    }
};