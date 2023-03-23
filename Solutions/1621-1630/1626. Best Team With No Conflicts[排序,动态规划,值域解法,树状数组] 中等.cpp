/*
** Problem: https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones
** Article: https://memcpy0.blog.csdn.net/article/details/117888925
** Author: memcpy0
*/

// 树状数组（变形）优化
class Solution {
private:
    static constexpr int MAX_LEN = 1000;
    int tree[MAX_LEN + 1];
    void update(int i, int maxSum) { // 更新maxSum[i]为maxSum,
        for (; i <= MAX_LEN; i += (i & (-i))) // i后面的maxSum[j]也受到影响
            tree[i] = max(tree[i], maxSum);
    }
    int query(int i) { // 返回max(maxSum[0:i+1])
        int ans = 0;
        for (; i; i -= (i & (-i)))
            ans = max(tree[i], ans);
        return ans;
    }
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; ++i)
            a[i] = {scores[i], ages[i]};
        sort(a, a + n);
        for (auto &[score, age] : a) { // 更新maxSum[age]]为max(maxsum[0:age+1])+score
            update(age, query(age) + score);
        }
        return query(MAX_LEN);
    }
};

/*
// 基于值域计算
class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; ++i)
            a[i] = {scores[i], ages[i]};
        sort(a, a + n);

        int u = *max_element(ages.begin(), ages.end());
        int max_sum[u + 1]; memset(max_sum, 0, sizeof(max_sum));
        for (auto &[score, age] : a)
            max_sum[age] = *max_element(max_sum, max_sum + age + 1) + score; // 枚举年龄不超过ages[i]的球队
        return *max_element(max_sum, max_sum + u + 1);
    }
};
*/

/*
// 排序+动态规划
class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; ++i)
            a[i] = {scores[i], ages[i]};
        sort(a, a + n);
        int f[n]; memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (a[j].second <= a[i].second) // 枚举年龄不超过ages[i]的队
                    f[i] = max(f[i], f[j]);
            f[i] += a[i].first;
        }
        return *max_element(f, f + n); 
    }
};
*/