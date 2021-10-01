/*
** Problem: https://leetcode-cn.com/problems/check-if-word-can-be-placed-in-crossword/
** Article: https://memcpy0.blog.csdn.net/article/details/120559958
** Author: memcpy0
*/
class Solution {
private:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(const vector<vector<char>>& b, const string& w, int i, int j, int k, int cur) {
        if (cur >= w.size()) return true;
        if (b[i][j] == '#' || (b[i][j] != ' ' && b[i][j] != w[cur])) return false;
        return dfs(b, w, i + d[k][0], j + d[k][1], k, cur + 1);
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '#' && (board[i][j] == ' ' || board[i][j] == word[0])) {
                    int ti0 = i + len - 1, ti1 = i - len + 1, tj0 = j + len - 1, tj1 = j - len + 1; 
                    if ((ti0 < m && board[ti0][j] != '#') && //up to down
                        (i == 0 || board[i - 1][j] == '#') &&
                        (ti0 == m - 1 || board[ti0 + 1][j] == '#') &&
                        dfs(board, word, i, j, 0, 0)) return true;
                    if ((ti1 >= 0 && board[ti1][j] != '#') && //down to up
                        (i == m - 1 || board[i + 1][j] == '#') &&
                        (ti1 == 0 || board[ti1 - 1][j] == '#') &&
                        dfs(board, word, i, j, 1, 0)) return true;
                    if ((tj0 < n && board[i][tj0] != '#') && //left to right
                        (j == 0 || board[i][j - 1] == '#') &&
                        (tj0 == n - 1 || board[i][tj0 + 1] == '#') &&
                        dfs(board, word, i, j, 2, 0)) return true;
                    if ((tj1 >= 0 && board[i][tj1] != '#') && //right to left
                        (j == n - 1 || board[i][j + 1] == '#') &&
                        (tj1 == 0 || board[i][tj1 - 1] == '#') &&
                        dfs(board, word, i, j, 3, 0)) return true;
                }
            }
        }
        return false;
    }
};