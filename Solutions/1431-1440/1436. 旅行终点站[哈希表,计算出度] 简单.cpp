/*
** Problem: https://leetcode-cn.com/problems/destination-city/
** Article: https://memcpy0.blog.csdn.net/article/details/109640507
** Author: memcpy0
*/
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> rec; //city : outdegree 
        for (const vector<string> &path : paths) ++rec[path[0]]; //起点城市的出度+1
        for (const vector<string> &path : paths)
            if (rec[path[1]] == 0) return path[1];
        return "";
    }
};