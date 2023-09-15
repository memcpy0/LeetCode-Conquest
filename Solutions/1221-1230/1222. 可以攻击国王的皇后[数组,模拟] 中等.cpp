/*
** Problem: https://leetcode.cn/problems/queens-that-can-attack-the-king
** Article: https://memcpy0.blog.csdn.net/article/details/132899953
** Author: memcpy0
*/
class Solution {
    const int directions[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        bool is_queen[8][8]{}; // 数组效率比哈希表高
        for (auto &q: queens) is_queen[q[0]][q[1]] = true;
        vector<vector<int>> ans;
        for (auto &d: directions) {
            int x = king[0] + d[0];
            int y = king[1] + d[1];
            while (0 <= x && x < 8 && 0 <= y && y < 8) {
                if (is_queen[x][y]) {
                    ans.push_back({x, y});
                    break;
                }
                x += d[0];
                y += d[1];
            }
        }
        return ans;
    }
};