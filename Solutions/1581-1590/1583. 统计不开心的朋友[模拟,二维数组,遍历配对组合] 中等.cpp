/*
** Problem: https://leetcode-cn.com/problems/count-unhappy-friends/
** Article: https://memcpy0.blog.csdn.net/article/details/108651283
** Author: memcpy0
*/
class Solution {
private:
    int prefer[510][510] = {0}, ans = 0;
    vector<bool> vis;
    void twoFriendsUnhappy(int x, int y, int u, int v) {
        if (prefer[x][u] < prefer[x][y] && prefer[u][x] < prefer[u][v]) { //x,u都不开心
            if (!vis[x]) ++ans, vis[x] = true;
            if (!vis[u]) ++ans, vis[u] = true;
        }
    }
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        for (int i = 0; i < n; ++i) //i和preferences[i][j]的亲近程度为j,越小越亲近 
            for (int j = 0; j < n - 1; ++j)  
                prefer[i][preferences[i][j]] = j; 
        vis.resize(n);
        for (int i = 0; i < pairs.size(); ++i) { //遍历配对组合
            for (int j = i + 1; j < pairs.size(); ++j) {
                int x = pairs[i][0], y = pairs[i][1], u = pairs[j][0], v = pairs[j][1];
                twoFriendsUnhappy(x, y, u, v); //一次检查能得出有两个人是否一起不开心
                twoFriendsUnhappy(x, y, v, u);
                twoFriendsUnhappy(y, x, u, v);
                twoFriendsUnhappy(y, x, v, u);
            }
        }
        return ans;
    }
};