/*
** Problem: https://leetcode.cn/problems/largest-values-from-labels/
** Article: https://memcpy0.blog.csdn.net/article/details/130825110
** Author: memcpy0
*/
class Solution { 
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) { 
        vector<int> id;
        int n = labels.size();
        for (int i = 0; i < n; ++i) id.push_back(i);
        sort(id.begin(), id.end(), [&](int a, int b) {
            return values[a] > values[b];
        }); 
        int ans = 0;
        unordered_map<int, int> hasUsed;
        for (int i = 0; i < n && numWanted; ++i) {
            int label = labels[id[i]];
            if (hasUsed[label] >= useLimit) continue; 
            ans += values[id[i]]; // 加上可选的最大的那个分数
            ++hasUsed[label];
            --numWanted;
        }
        return ans;
    }
};