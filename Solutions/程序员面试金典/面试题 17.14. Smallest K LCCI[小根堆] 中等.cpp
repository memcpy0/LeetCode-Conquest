/*
** Problem: https://leetcode-cn.com/problems/smallest-k-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/120108542
** Author: memcpy0
*/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const int &v : arr) pq.push(v);
        vector<int> ans;
        while (k-- > 0) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};