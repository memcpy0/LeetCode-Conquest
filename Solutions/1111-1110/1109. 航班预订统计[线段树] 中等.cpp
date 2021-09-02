/*
** Problem: https://leetcode-cn.com/problems/corporate-flight-bookings/
** Article: https://memcpy0.blog.csdn.net/article/details/116857235
** Author: memcpy0
*/
class Solution {
private:
    struct node {
        long long l, r, v, lz;
        node() {}
        node(int _l, int _r) : l(_l), r(_r), v(0), lz(0) {}
    };
    static const int maxn = 2e4 + 10;
    node tree[maxn * 4];
    void init() { 
        for (int i = 0; i < maxn * 4; ++i) 
            tree[i].l = tree[i].r = tree[i].v = tree[i].lz = 0;
    }
    void lazy(int k, int v) { //懒标记
        tree[k].v += v;  //更新值
        tree[k].lz += v; //做懒标记
    }
    void pushdown(int k) { //下传懒标记并进行实际修改
        lazy(k << 1, tree[k].lz);      //传递懒标记给左孩子
        lazy(k << 1 | 1, tree[k].lz); //传递懒标记给右孩子
        tree[k].lz = 0;                //清除自己的懒标记
    }
    void pushup(int k) { //上推值
        tree[k].v = tree[k << 1].v + tree[k << 1 | 1].v; //内部节点的值为孩子节点值的和
    }
    void build(int k, int l, int r) { //创建线段树
        tree[k] = node(l, r);  //初始化
        if (l == r) return;    //叶子节点,即原始的数组值,此处为0
        int mid = l + r >> 1;
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
    }
    void updateRange(int k, int l, int r, int v) { //区间[l,r]加v
        if (tree[k].l >= l && tree[k].r <= r) { //做懒标记,不进行实际区间修改
            lazy(k, v);
            return;
        }
        if (tree[k].lz) pushdown(k); //存在懒标记时下推
        int mid = tree[k].l + tree[k].r >> 1;
        if (l <= mid) updateRange(k << 1, l, r, v);
        if (r > mid) updateRange(k << 1 | 1, l, r, v);
        pushup(k); //修改后上推值
    }
    int query(int k, int l, int r) { //区间查询[l,r]的和值,也可用于单点查询
        if (tree[k].l >= l && tree[k].r <= r) return tree[k].v;
        if (tree[k].lz) pushdown(k); //存在懒标记时下推
        int mid = tree[k].l + tree[k].r >> 1;
        int ans = 0;
        if (l <= mid) ans += query(k << 1, l, r);
        if (r > mid) ans += query(k << 1 | 1, l, r);
        return ans;
    }
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans; 
        build(1, 1, n);
        for (const vector<int>& book : bookings) updateRange(1, book[0], book[1], book[2]);
        for (int i = 0; i < n; ++i) ans.push_back(query(1, i + 1, i + 1)); 
        return ans;
    }
};