/*
** Problem: https://leetcode.cn/problems/reconstruct-itinerary
** Article: https://memcpy0.blog.csdn.net/article/details/108256896
** Author: memcpy0
*/
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
    vector<string> stk;
    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK"); // JFK要么是欧拉回路的一点,要么是欧拉通路的起点 
        reverse(stk.begin(), stk.end());
        return stk;
    }
};