/*
** Problem: https://leetcode-cn.com/problems/grid-game/
** Article: https://memcpy0.blog.csdn.net/article/details/120559913
** Author: memcpy0
*/
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        using ll = long long;
        int n = grid[0].size();
        ll ans = numeric_limits<ll>::max(), upsum = 0, down = 0;
        for (int i = 0; i < n; ++i) upsum += grid[0][i];
        for (int i = 0; i < n; ++i) { //假设从(0,i)点下移
            upsum -= grid[0][i];
            ans = min(ans, max(upsum, down));
            down += grid[1][i];
        }
        return ans;
    }
};