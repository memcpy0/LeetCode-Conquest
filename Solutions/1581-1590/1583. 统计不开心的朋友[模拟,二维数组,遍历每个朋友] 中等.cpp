/*
** Problem: https://leetcode-cn.com/problems/count-unhappy-friends/
** Article: https://memcpy0.blog.csdn.net/article/details/108651283
** Author: memcpy0
*/
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& prefers, vector<vector<int>>& pairs) {
        int ans = 0, pairsArr[n], ranks[n][n];
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n - 1; ++j) 
                ranks[i][prefers[i][j]] = j; //i对v的亲近程度,值越小越亲近
        for (const vector<int> &p : pairs) pairsArr[p[0]] = p[1], pairsArr[p[1]] = p[0];
        for (int x = 0; x < n; ++x) { //遍历所有朋友i
            int y = pairsArr[x]; //x<->y
            for (int j = 0; j < n - 1 && prefers[x][j] != y; ++j) { //从最亲近到最不亲近遍历x的朋友
                int u = prefers[x][j], v = pairsArr[u]; //u<->v; 此处x与u的亲近程度胜过x与y
                if (ranks[u][x] < ranks[u][v]) { //比较u与x的亲近程度、u与v的亲近程度,判断x是否不开心
                    ++ans; 
                    break; //及时退出,避免重复计算人数
                }
            }
        }
        return ans;
    }
};