/*
** Problem: https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to
** Article: https://memcpy0.blog.csdn.net/article/details/132805314
** Author: memcpy0
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> rec;
        vector<vector<int>> ans;
        for (int i{}; auto& v : groupSizes) {
            rec[v].push_back(i++);
            if (rec[v].size() == v)
                ans.push_back(exchange(rec[v], {}));
        }
        return ans;
    }
};