/*
** Problem: https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence
** Article: https://memcpy0.blog.csdn.net/article/details/132265378
** Author: memcpy0
*/
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        // 利润从大到小排序
        sort(items.begin(), items.end(), [&](const auto &a, const auto &b) {
            return a[0] > b[0];
        });
        long long totalProfit = 0, ans = 0;
        // 利润和 totalProfit 在最大 k 个利润的基础上不会变大
        unordered_set<int> vis; // 判断类别是否出现过
        stack<int> dup; // 重复类别的利润,栈顶最小
        for (int i = 0, n = items.size(); i < n; ++i) {
            int profit = items[i][0], category = items[i][1];
            if (i < k) {
                totalProfit += profit;
                if (vis.count(category)) dup.push(profit);
                else vis.insert(category);
            } // 如果新添加的项目的类别之前选过了,则distinct_categories不会变大 
            else if (!dup.empty() && !vis.count(category)) {
                // 如果新添加的项目的类别之前没有选过,distinct_categories^2可能变大
                vis.insert(category);
                // 我们移除最小利润的项目
                // 如果移除的项目的类别只有1个,则distinct_categories-1+1,不变,但总利润可能变小
                // 如果移除的项目的类别有多个,则distinct_categories+1,这种情况就是可行的
                totalProfit -= dup.top(); dup.pop(); // 移除掉一个重复且利润最小的项目
                totalProfit += profit; // 本项目目前只出现了一次,不应加入dup中;且以后出现也不会被考虑
            }
            ans = max(ans, totalProfit + (long long)(vis.size() * vis.size()));
        }
        return ans;
    }
};