/*
** Problem: https://leetcode-cn.com/problems/sudoku-solver/
** Article: https://memcpy0.blog.csdn.net/article/details/120581936
** Author: memcpy0
*/
class Solution {
private:
    bool row[9][9] = {false}, col[9][9] = {false}, blocks[9][9] = {false};
    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y == 9) return dfs(board, x + 1, 0); //某行被填完,转向下一行
        if (x == 9) return true; //整个数独被填完
        if (board[x][y] != '.') return dfs(board, x, y + 1); //填当前行的下一列
        for (int i = 0; i < 9; ++i) {
            int b = x / 3 * 3 + y / 3;
            if (!row[x][i] && !col[y][i] && !blocks[b][i]) {
                board[x][y] = (char)(i + '1');
                row[x][i] = col[y][i] = blocks[b][i] = true;
                if (dfs(board, x, y + 1)) return true; //填当前行的下一列,成功则跳出
                board[x][y] = '.';
                row[x][i] = col[y][i] = blocks[b][i] = false;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') { //事先记录每行/每列/每个3x3宫内哪些数字已被使用
                    int num = board[i][j] - '1', blockIdx = i / 3 * 3 + j / 3;
                    row[i][num] = col[j][num] = blocks[blockIdx][num] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
};