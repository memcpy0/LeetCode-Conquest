/*
** Problem: https://leetcode.cn/problems/sort-the-people/
** Article: https://memcpy0.blog.csdn.net/article/details/130395974
** Author: memcpy0
*/
class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        int n = names.size(), maxn = *max_element(heights.begin(), heights.end());
        int rec[maxn + 1]; memset(rec, -1, sizeof(rec));
        for (int i = 0; i < n; ++i) rec[heights[i]] = i;
        vector<string> ans;
        for (int i = maxn; i >= 1; --i)
            if (rec[i] != -1) ans.push_back(names[rec[i]]);
        return ans;
    }
};

/*
class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        int n = names.size(), id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](const auto &i, const auto &j) {
            return heights[i] > heights[j];
        });
        vector<string> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = names[id[i]];
        return ans;
    }
};
*/