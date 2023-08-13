/*
** Problem: https://leetcode.cn/problems/swim-in-rising-water
** Article: https://memcpy0.blog.csdn.net/article/details/132256075
** Author: memcpy0
*/
// BEST: 二分答案+BFS
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        typedef pair<int, int> pii;
        int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        auto check = [&](int lim) { // 能否在<=lim时间从左上到右小
            bool vis[n][n]; memset(vis, false, sizeof(vis));
            queue<pii> q;
            if (grid[0][0] <= lim) {
                q.push(pii(0, 0)); vis[0][0] = true;
            }
            while (!q.empty()) {
                pii p = q.front(); q.pop();
                int i = p.first, j = p.second;
                if (i == n - 1 && j == n - 1) return true;
                for (int k = 0; k < 4; ++k) {
                    int x = i + d[k][0], y = j + d[k][1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] > lim || vis[x][y])
                        continue;
                    q.push(pii(x, y));
                    vis[x][y] = true;
                }
            }
            return vis[n - 1][n - 1];
        };
        int l = grid[0][0], r = n * n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

// 计数排序+并查集
class Solution {
    private class UnionFind {
        private int[] parent;
        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        public int find(int x) {
            return x != parent[x] ? parent[x] = find(parent[x]) : x;
        }
        public boolean isConnected(int x, int y) { return find(x) == find(y); }
        public void union(int p, int q) {
            int rp = find(p), rq = find(q);
            if (rp == rq) return;
            parent[rp] = rq;
        }
    }
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int len = n * n;
        int[] heightToIndex = new int[len]; // 方格的高度:方格的坐标
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                heightToIndex[grid[i][j]] = i * n + j;

        int[][] d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        UnionFind unionFind = new UnionFind(len);
        for (int i = 0; i < len; ++i) { // 高度从低到高
            int x = heightToIndex[i] / n, y = heightToIndex[i] % n;
            for (int j = 0; j < 4; ++j) {
                int u = x + d[j][0], v = y + d[j][1];
                if (u >= 0 && u < n && v >= 0 && v < n && grid[u][v] <= i)
                    unionFind.union(heightToIndex[i], u * n + v); // 合并
            }
            if (unionFind.isConnected(0, len - 1)) return i; // 连通
        }
        return -1;
    }
}

// 最小瓶颈路: Kruskal
class Solution {
    private class UnionFind {
        private int[] parent;
        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        public int find(int x) {
            return x != parent[x] ? parent[x] = find(parent[x]) : x;
        }
        public boolean isConnected(int x, int y) { return find(x) == find(y); }
        public void union(int p, int q) {
            int rp = find(p), rq = find(q);
            if (rp == rq) return;
            parent[rp] = rq;
        }
    }
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int len = n * n;
        int[][] d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        UnionFind unionFind = new UnionFind(len);

        // 预处理所有无向边
        // edge存[a,b,w]: 代表从a到b所需的时间点为w
        // 虽然我们可以往四个方向移动,但只要对于每个点都添加「向右」和「向下」
        // 两条边的话，其实就已经覆盖了所有边
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = i * n + j;
                int a, b, w;
                if (i + 1 < n) {
                    a = index; b = (i + 1) * n + j;
                    w = Math.max(grid[i][j], grid[i + 1][j]);
                    edges.add(new int[]{a, b, w});
                }
                if (j + 1 < n) {
                    a = index; b = i * n + (j + 1);
                    w = Math.max(grid[i][j], grid[i][j + 1]);
                    edges.add(new int[]{a, b, w});
                }   
            }
        }
        Collections.sort(edges, (a, b) -> a[2] - b[2]); // 根据w权值升序
        // 从「小边」开始添加,当某一条边应用之后,恰好使得「起点」和「结点」联通
        // 那么代表找到了「最短路径」中的「权重最大的边」
        int start = 0, end = len - 1;
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            unionFind.union(a, b);
            if (unionFind.isConnected(start, end)) return w;
        }
        return 0;
    }
}

// 最小瓶颈路: PRIM
class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        minHeap.offer(new int[]{0, 0, grid[0][0]});
        
        boolean[][] vis = new boolean[n][n];
        // dist[i][j]表示 到顶点[i,j] 要等待的最少时间
        int[][] dist = new int[n][n];
        for (int[] row : dist) Arrays.fill(row, n * n);
        dist[0][0] = grid[0][0];

        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!minHeap.isEmpty()) { // 找最短的边
            int[] front = minHeap.poll();
            int x = front[0], y = front[1], d = front[2];
            if (vis[x][y]) continue;
            vis[x][y] = true;
            if (x == n - 1 && y == n - 1) return dist[n - 1][n - 1];
            // 更新
            for (int i = 0; i < 4; ++i) {
                int u = x + directions[i][0], v = y + directions[i][1];
                if (u >= 0 && u < n && v >= 0 && v < n 
                    && !vis[u][v] && // prim算法
                    Math.max(d, grid[u][v]) < dist[u][v]) {
                        dist[u][v] = Math.max(d, grid[u][v]);
                        minHeap.offer(new int[]{u, v, dist[u][v]});
                    }
            }
        }
        return -1;
    }
}
