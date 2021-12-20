/*
** Problem: https://leetcode-cn.com/problems/battleships-in-a-board/
** Article: https://memcpy0.blog.csdn.net/article/details/122033533
** Author: memcpy0
*/
class Solution {
    public int countBattleships(char[][] board) {
        int ans = 0;
        for (int i = 0, m = board.length; i < m; ++i) {
            for (int j = 0, n = board[i].length; j < n; ++j) {
                if (i > 0 && board[i - 1][j] == 'X') continue;
                if (j > 0 && board[i][j - 1] == 'X') continue;
                if (board[i][j] == 'X') ++ans; // 正繁则反
            }
        }
        return ans;
    }
}