/*
** Problem: https://leetcode-cn.com/problems/destination-city/
** Article: https://memcpy0.blog.csdn.net/article/details/109640507
** Author: memcpy0
*/
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> rec; //记录每个点是否有出度
        for (const vector<string>& path : paths) rec[path[0]] = true;
        for (const vector<string>& path : paths) 
            if (rec[path[1]] == false) return path[1];
        return "";
    }
};