/*
** Problem: https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/
** Article: https://memcpy0.blog.csdn.net/article/details/131263891
** Author: memcpy0
*/
// BEST: 求最大+鸽巢原理
class Solution {
    public int numTimesAllBlue(int[] flips) {
        int ans = 0, mx = 0;
        for (int i = 0; i < flips.length; ++i) {
            mx = Math.max(mx, flips[i]);
            if (mx == i + 1) ++ans;
        }
        return ans;
    }
}

// 求和
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0;
        long long sum = 0;
        for (int i = 1, n = flips.size(); i <= n; ++i) {
            sum += flips[i - 1];
            if (sum == (long long)i * (i + 1) / 2) ++ans;
        }
        return ans;
    }
};

// 树状数组
class Solution {
private:
    vector<int> tree;
    int n;
    int lowbit(int i) { return i & -i; }
    void add(int i, int v) {
        while (i <= n) {
            tree[i] += v;
            i += lowbit(i);
        }
    }
    int sum(int i) {
        int ans = 0;
        while (i) {
            ans += tree[i];
            i -= lowbit(i);
        }
        return ans;
    }
public:
    int numTimesAllBlue(vector<int>& flips) {
        n = flips.size();
        tree.resize(n + 1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            add(flips[i], 1);
            if (sum(i + 1) == i + 1) ++ans;
        }
        return ans;
    }
};