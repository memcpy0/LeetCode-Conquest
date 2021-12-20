/*
** Problem: https://leetcode-cn.com/problems/battleships-in-a-board/
** Article: https://memcpy0.blog.csdn.net/article/details/122033533
** Author: memcpy0
*/
class Solution {
    public int countBattleships(char[][] board) {
        int m = board.length, n = board[0].length, ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'X') continue;
                board[i][j] = '-';
                for (int k = i + 1; k < m && board[k][j] == 'X'; k++) board[k][j] = '-';
                for (int k = j + 1; k < n && board[i][k] == 'X'; k++) board[i][k] = '-';
                ++ans;
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == '-') board[i][j] = 'X';
        return ans;
    }
}