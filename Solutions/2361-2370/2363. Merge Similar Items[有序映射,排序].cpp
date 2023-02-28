/*
** Problem: https://leetcode.cn/problems/merge-similar-items/
** Article: https://memcpy0.blog.csdn.net/article/details/129273465
** Author: memcpy0
*/
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> rec;
        for (const auto& v : items1) rec[v[0]] += v[1];
        for (const auto& v : items2) rec[v[0]] += v[1];
        vector<vector<int>> ans;
        for (const auto& it : rec) ans.push_back({it.first, it.second});
        return ans;
    }
};