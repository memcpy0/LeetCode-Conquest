/*
** Problem: https://leetcode.cn/problems/min-cost-to-connect-all-points/
** Article: https://memcpy0.blog.csdn.net/article/details/132926389
** Author: memcpy0
*/
// BEST: 建堆优化的Kruskal
class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;

public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return true;
    }
};
class BIT {
public:
    vector<int> tree, idRec;
    int n;

    BIT(int _n) {
        n = _n;
        tree.resize(n, INT_MAX);
        idRec.resize(n, -1);
    }

    int lowbit(int k) {
        return k & (-k);
    }

    void update(int pos, int val, int id) {
        while (pos > 0) {
            if (tree[pos] > val) {
                tree[pos] = val;
                idRec[pos] = id;
            }
            pos -= lowbit(pos);
        }
    }

    int query(int pos) {
        int minval = INT_MAX;
        int j = -1;
        while (pos < n) {
            if (minval > tree[pos]) {
                minval = tree[pos];
                j = idRec[pos];
            }
            pos += lowbit(pos);
        }
        return j;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {
    }
    bool operator<(const Edge& a) const {
        return len < a.len;
    }
};

struct Pos {
    int id, x, y;
    bool operator<(const Pos& a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
};

class Solution {
public:
    vector<Edge> edges;
    vector<Pos> pos;

    void build(int n) {
        sort(pos.begin(), pos.end());
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            a[i] = pos[i].y - pos[i].x;
            b[i] = pos[i].y - pos[i].x;
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int num = b.size();
        BIT bit(num + 1);
        for (int i = n - 1; i >= 0; i--) {
            int poss = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
            int j = bit.query(poss);
            if (j != -1) {
                int dis = abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
                edges.emplace_back(dis, pos[i].id, pos[j].id);
            }
            bit.update(poss, pos[i].x + pos[i].y, i);
        }
    }

    void solve(vector<vector<int>>& points, int n) {
        pos.resize(n);
        for (int i = 0; i < n; i++) {
            pos[i].x = points[i][0];
            pos[i].y = points[i][1];
            pos[i].id = i;
        }
        build(n);
        for (int i = 0; i < n; i++) {
            swap(pos[i].x, pos[i].y);
        }
        build(n);
        for (int i = 0; i < n; i++) {
            pos[i].x = -pos[i].x;
        }
        build(n);
        for (int i = 0; i < n; i++) {
            swap(pos[i].x, pos[i].y);
        }
        build(n);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        solve(points, n);

        DisjointSetUnion dsu(n);
        sort(edges.begin(), edges.end());
        int ret = 0, num = 1;
        for (auto& [len, x, y] : edges) {
            if (dsu.unionSet(x, y)) {
                ret += len;
                num++;
                if (num == n) {
                    break;
                }
            }
        }
        return ret;
    }
};