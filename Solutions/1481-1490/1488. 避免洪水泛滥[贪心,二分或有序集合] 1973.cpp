/*
** Problem: https://leetcode.cn/problems/avoid-flood-in-the-city
** Article: https://memcpy0.blog.csdn.net/article/details/133811591
** Author: memcpy0
*/
// BEST: 贪心+二分+有序集合
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        set<int> st;
        unordered_map<int, int> rec;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) st.insert(i);
            else {
                ans[i] = -1;
                if (rec.count(rains[i])) { 
                    // 找到第一个>rec[rains[i]](即该湖泊上次下雨的时间)的晴天下标
                    auto it = st.lower_bound(rec[rains[i]]);
                    if (it == st.end()) return {};
                    ans[*it] = rains[i];
                    st.erase(it);
                }
                rec[rains[i]] = i;
            }
        }
        return ans;
    }
};