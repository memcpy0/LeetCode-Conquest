/*
** Problem: https://leetcode-cn.com/problems/maximal-network-rank/
** Article: https://memcpy0.blog.csdn.net/article/details/109115129
** Author: memcpy0
*/
// O(m+n)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connect(n, vector<bool>(n, false)); // 任意两个城市之间是否存在直接相连道路
        vector<int> degree(n); // 与每个城市直接相连的道路数(顶点度数)
        for (auto road : roads) {
            int x = road[0], y = road[1];
            connect[x][y] = connect[y][x] = true;
            ++degree[x], ++degree[y];
        } 
        int first = -1, second = -2; // 最大相连数 // 次大相连数   
        vector<int> firstArr, secondArr; // 相连道路数为最大、次大值的所有城市
        for (int i = 0; i < n; ++i) {
            if (degree[i] > first) {
                second = first;
                secondArr = firstArr;
                first = degree[i];
                firstArr.clear();
                firstArr.emplace_back(i);
            } else if (degree[i] == first) {
                firstArr.emplace_back(i);
            } else if (degree[i] > second){
                secondArr.clear();
                second = degree[i];
                secondArr.emplace_back(i);
            } else if (degree[i] == second) {
                secondArr.emplace_back(i);
            }
        }
        // 最大值只有一个元素,枚举所有次大值城市(可能一个或多个),网络秩=最大值+次大值-两个城市相连道路数
        if (firstArr.size() == 1) { // 最大值的城市个数
            int u = firstArr[0];
            for (int v : secondArr)
                if (!connect[u][v])
                    return first + second; 
            return first + second - 1;
        } else { // 最大值不止一个元素,枚举所有最大值的城市对,网络秩=2*最大值两个城市相连道路数
            int m = roads.size();
            if (firstArr.size() * (firstArr.size() - 1) / 2 > m) { // 存在一对城市没有直接相连道路
                return first * 2;
            }
            for (int u: firstArr)
                for (int v: firstArr)
                    if (u != v && !connect[u][v])
                        return first * 2; 
            return first * 2 - 1;
        }
    }
};