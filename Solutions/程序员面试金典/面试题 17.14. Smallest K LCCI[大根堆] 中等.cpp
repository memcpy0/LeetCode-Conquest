/*
** Problem: https://leetcode-cn.com/problems/smallest-k-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/120108542
** Author: memcpy0
*/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) return {}; //注意k=0时,需要直接返回{}
        priority_queue<int, vector<int>, less<int>> pq;
        for (const int &v : arr) {
            if (pq.size() < k) pq.push(v);
            else if (v < pq.top()) { //不然此处会出错
                pq.pop();
                pq.push(v);
            }
        }
        vector<int> ans(k);
        while (k-- > 0) {
            ans[k] = pq.top();
            pq.pop();
        }
        return ans;
    }
};