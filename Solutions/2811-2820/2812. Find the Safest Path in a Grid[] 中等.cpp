/*
** Problem: https://leetcode.cn/problems/find-the-safest-path-in-a-grid/
** Article: https://memcpy0.blog.csdn.net/article/details/132261734
** Author: memcpy0
*/

// 最大瓶颈路: Kruskal
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
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size(), m = grid.get(0).size();
        int len = n * m;
        int[][] d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int[][] minDist = new int[n][n]; // 最近的小偷到(i,j)的距离
        for (int[] row : minDist) Arrays.fill(row, -1);
        Queue<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (grid.get(i).get(j) == 1) {
            q.offer(new int[]{i, j});
            minDist[i][j] = 0;
        }
        while (!q.isEmpty()) {
            int[] front = q.poll();
            int i = front[0], j = front[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + d[k][0], y = j + d[k][1]; // minDist[x][y]看最近的小偷
                if (x < 0 || x >= n || y < 0 || y >= n || minDist[x][y] >= 0) continue;
                q.offer(new int[]{x, y});
                minDist[x][y] = minDist[i][j] + 1;
            }
        }

        UnionFind unionFind = new UnionFind(len);
        // 预处理所有无向边 edge存[a,b,w]
        // 虽然我们可以往四个方向移动,但只要对于每个点都添加「向右」和「向下」
        // 两条边的话，其实就已经覆盖了所有边
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int index = i * m + j;
                int a, b, w;
                if (i + 1 < n) {
                    a = index; b = (i + 1) * m + j;
                    w = Math.min(minDist[i][j], minDist[i + 1][j]);
                    edges.add(new int[]{a, b, w});
                }
                if (j + 1 < m) {
                    a = index; b = i * m + (j + 1);
                    w = Math.min(minDist[i][j], minDist[i][j + 1]);
                    edges.add(new int[]{a, b, w});
                }
            }
        }
        Collections.sort(edges, (a, b) -> b[2] - a[2]); // 根据w权值降序
        int start = 0, end = len - 1;
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            unionFind.union(a, b);
            if (unionFind.isConnected(start, end)) return w;
        }
        return 0;
    }
}
// 最大瓶颈路: PRIM
class Solution {
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size(), m = grid.get(0).size();
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int[][] minDist = new int[n][n]; // 最近的小偷到(i,j)的距离
        for (int[] row : minDist) Arrays.fill(row, -1);
        Queue<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (grid.get(i).get(j) == 1) {
            q.offer(new int[]{i, j});
            minDist[i][j] = 0;
        }
        while (!q.isEmpty()) {
            int[] front = q.poll();
            int i = front[0], j = front[1];
            for (int k = 0; k < 4; ++k) { // minDist[x][y]看最近的小偷
                int x = i + directions[k][0], y = j + directions[k][1];
                if (x < 0 || x >= n || y < 0 || y >= n || minDist[x][y] >= 0) continue;
                q.offer(new int[]{x, y});
                minDist[x][y] = minDist[i][j] + 1;
            }
        }
        
        boolean[][] vis = new boolean[n][m];
        int[][] dist = new int[n][m];
        for (int[] row : dist)
            Arrays.fill(row, Integer.MIN_VALUE);
        dist[0][0] = minDist[0][0];

        // 必须将 先前加入队列时的边权重 加入int[]中
        Queue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[2] - a[2]);
        maxHeap.offer(new int[]{0, 0, dist[0][0]});

        while (!maxHeap.isEmpty()) { // 找最长的边
            int[] front = maxHeap.poll();
            int x = front[0], y = front[1], d = front[2];
            if (vis[x][y]) continue;
            vis[x][y] = true;
            if (x == n - 1 && y == m - 1) break;
            // 更新
            for (int i = 0; i < 4; ++i) {
                int u = x + directions[i][0], v = y + directions[i][1];
                if (u >= 0 && u < n && v >= 0 && v < m 
                    && !vis[u][v] && // prim算法
                    Math.min(d, minDist[u][v]) > dist[u][v]) {
                        dist[u][v] = Math.min(d, minDist[u][v]);
                        maxHeap.offer(new int[]{u, v, dist[u][v]});
                    }
            }
        }
        return dist[n - 1][m - 1];
    }
}