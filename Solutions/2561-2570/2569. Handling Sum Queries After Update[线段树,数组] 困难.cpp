/*
** Problem: https://leetcode.cn/problems/handling-sum-queries-after-update/
** Article: https://memcpy0.blog.csdn.net/article/details/131957862
** Author: memcpy0
*/
// BEST: 线段树
struct SegNode {
    int l, r, sum;
    bool lazyTag;
    SegNode() {
        l = r = sum = 0;
        lazyTag = false;
    }
};
class SegTree {
private:
    vector<SegNode> arr;
public:
    SegTree(vector<int>& nums) {
        int n = nums.size();
        arr = vector<SegNode>(n * 4 + 1);
        build(1, 0, n - 1, nums);
    }
    void build(int id, int l, int r, const vector<int>& nums) {
        arr[id].l = l;
        arr[id].r = r;
        arr[id].lazyTag = false;
        if (l == r) {
            arr[id].sum = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * id, l, mid, nums);
        build(2 * id + 1, mid + 1, r, nums);
        arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum;
    }
    // pushdown函数：下传懒标记，将当前区间的修改情况下放到其左右孩子结点
    void pushdown(int x) {
        if (arr[x].lazyTag) {
            arr[2 * x].lazyTag = !arr[2 * x].lazyTag;
            arr[2 * x].sum = arr[2 * x].r - arr[2 * x].l + 1 - arr[2 * x].sum; // 翻转后1的个数
            arr[2 * x + 1].lazyTag = !arr[2 * x + 1].lazyTag;
            arr[2 * x + 1].sum = arr[2 * x + 1].r - arr[2 * x + 1].l + 1 - arr[2 * x + 1].sum;
            arr[x].lazyTag = false;
        }
    }
    /** 区间修改 **/
    void modify(int id, int l, int r) {
        if (arr[id].l >= l && arr[id].r <= r) {
            arr[id].sum = (arr[id].r - arr[id].l + 1) - arr[id].sum;
            arr[id].lazyTag = !arr[id].lazyTag;
            return;
        }
        pushdown(id);
        int mid = (arr[id].l + arr[id].r) >> 1;
        if (arr[2 * id].r >= l) modify(2 * id, l, r);
        if (arr[2 * id + 1].l <= r) modify(2 * id + 1, l, r);
        arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum;
    }
    /** 区间查询 **/
    int query(int id, int l, int r) {
        if (arr[id].l >= l && arr[id].r <= r) return arr[id].sum;
        if (arr[id].r < l || arr[id].l > r) return 0;
        pushdown(id);
        int ans = 0;
        if (arr[2 * id].r >= l) ans += query(2 * id, l, r);
        if (arr[2 * id + 1].l <= r) ans += query(2 * id + 1, l, r);
        return ans;
    }
    int sumRange(int left, int right) {
        return query(1, left, right);
    }
    void reverseRange(int left, int right) {
        modify(1, left, right);
    }
};
class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        SegTree tree(nums1);
        long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<long long> ans;
        for (int i = 0; i < m; ++i) {
            if (queries[i][0] == 1) {
                int l = queries[i][1];
                int r = queries[i][2];
                tree.reverseRange(l, r);
            } else if (queries[i][0] == 2) {
                sum += (long long) tree.sumRange(0, n - 1) * queries[i][1];
            } else if (queries[i][0] == 3) {
                ans.emplace_back(sum);
            }
        }
        return ans;
    }
};