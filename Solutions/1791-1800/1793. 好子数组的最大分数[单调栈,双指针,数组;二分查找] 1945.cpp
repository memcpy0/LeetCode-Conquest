/*
** Problem: https://leetcode.cn/problems/maximum-score-of-a-good-subarray/
** Article: https://memcpy0.blog.csdn.net/article/details/133980567
** Author: memcpy0
*/
// BEST: 两边的下标
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int width = 0;
            int v = i < n ? nums[i] : 0;
            while (!st.empty() && v < nums[st.top()]) { // 下标
                int idx = st.top(); st.pop();
                int l_idx = st.empty() ? 0 : (st.top() + 1);
                int r_idx = i - 1;
                if (l_idx <= k && r_idx >= k)
                    ans = max(ans, nums[idx] * (r_idx - l_idx + 1)); // 高度*总宽度
            }
            st.push(i);
        }
        return ans;
    }
};
// leftWidth+rightWidth,模仿84题.柱状图中的最大矩形
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        typedef pair<int, int> pii;
        stack<pii> st;
        int n = nums.size();
        vector<int> leftWidth(n);
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int width = 0;
            int v = i < n ? nums[i] : 0;
            while (!st.empty() && v < nums[st.top().first]) { // 下标
                pii tmp = st.top(); st.pop();
                int rightWidth = width; // nums[i]右边的宽度
                width += tmp.second; // 宽度
                if (tmp.first - leftWidth[tmp.first] + 1 <= k && tmp.first + rightWidth >= k)
                    ans = max(ans, nums[tmp.first] * width); // 高度*总宽度
            }
            st.push({i, width + 1});
            if (i < n) leftWidth[i] = width + 1; // 更新nums[i]左边的宽度,包括nums[i]
        }
        return ans;
    }
};