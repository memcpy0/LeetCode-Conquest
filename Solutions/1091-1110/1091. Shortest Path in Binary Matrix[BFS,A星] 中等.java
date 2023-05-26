/*
** Problem: https://leetcode.cn/problems/shortest-path-in-binary-matrix/
** Article: https://memcpy0.blog.csdn.net/article/details/130893597
** Author: memcpy0
*/
// 切比雪夫距离，从点x到点y的距离为max(dx, dy)
class Solution {
    int n = 0;
    public class Node {
        public int x, y; 
        public int cost; // 用于启发式函数评估
        public Node(int start, int end, int step) {
            this.x = start;
            this.y = end;
            this.cost = distance(x, y, step);
        } 
        public int distance(int x, int y, int step) {
            return step + Math.max(n - 1 - x, n - 1 - y); // 已走距离+到目标的切比雪夫距离
        }
    };  
    private int[][] d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    public int shortestPathBinaryMatrix(int[][] grid) {
        n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1; // 不可能出发或到达
        if (n <= 2) return n; // 1x1 2x2
        PriorityQueue<Node> q = new PriorityQueue<>(Comparator.comparingInt(v -> v.cost)); // 小顶堆 // (a, b) -> a.cost - b.cost
        q.add(new Node(0, 0, 1));
        grid[0][0] = 1;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            int x = cur.x;
            int y = cur.y; 
            if (x == n - 1 && y == n - 1) return grid[x][y];
            for (int i = 0; i < 8; ++i) {
                int tx = x + d[i][0];
                int ty = y + d[i][1]; // 注意判断 grid[tx][ty] > grid[x][y] + 1
                if (tx >= 0 && tx < n && ty >= 0 && ty < n && (
                    grid[tx][ty] == 0 || grid[tx][ty] > grid[x][y] + 1)) {
                    grid[tx][ty] = grid[x][y] + 1; // 标记遍历过,避免重复
                    q.add(new Node(tx, ty, grid[tx][ty]));
                }
            } 
        }
        return -1;
    } 
}

// BFS
/* 
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1; // 不可能出发或到达
        if (n <= 2) return n; // 1x1 2x2
        var q = new ArrayDeque<Integer>();
        int[][] d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; 
        q.offer(0);
        grid[0][0] = 1;
        int step = 1;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int u = q.poll();
                int x = u / n, y = u % n;
                if (x == n - 1 && y == n - 1) return step;
                for (int j = 0; j < 8; ++j) {
                    int tx = x + d[j][0], ty = y + d[j][1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n && grid[tx][ty] == 0) {
                        q.offer(tx * n + ty);  
                        grid[tx][ty] = 1;
                    }
                }
            }
            ++step;
        }
        return -1;
    }
}
*/

/* // 欧几里得距离
class Solution {
    static class Node {
        public int x, y;
        public int step;
        public double cost; // 用于启发式函数评估
        public Node(int start, int end, int step) {
            this.x = start;
            this.y = end;
            this.step = step;
        }
        public Node(int start, int end, int step, double cost) {
            this.x = start;
            this.y = end;
            this.step = step;
            this.cost = cost;
        }
        // 用于输出路径
        public Node parent = null;
        public Node getParent() { return parent; }
        public void setParent(Node parent) { this.parent = parent; }
        // 用于优先队列
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Node node = (Node) o;
            return x == node.x && y == node.y;
        }
        @Override
        public int hashCode() { return Objects.hash(x, y); }
    }; 
    private int pathLength(Node node) { // 输出路径的方法
        if (node == null) return 0;
        int pathLength = 1;
        while (node.getParent() != null) {
            node = node.getParent();
            pathLength++;
        }
        return pathLength;
    }
    private int[][] d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1; // 不可能出发或到达
        if (n <= 2) return n; // 1x1 2x2
        PriorityQueue<Node> q = new PriorityQueue<>(10, (i, j) -> Double.compare(i.cost, j.cost));
        q.add(new Node(0, 0, 1, 0));
        grid[0][0] = 1;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            int x = cur.x;
            int y = cur.y;
            int step = cur.step;
            if (x == n - 1 && y == n - 1) return step;
            for (int i = 0; i < 8; ++i) {
                int tx = x + d[i][0];
                int ty = y + d[i][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n && grid[tx][ty] == 0) {
                    double cost = cur.cost + 1 + distance(tx, ty, x, y); // 之前的距离+1+现在新增的距离
                    Node next = new Node(tx, ty, step + 1, cost);
                    if (q.contains(next)) continue; // 不能重复入队
                    next.setParent(cur); // 保存路径方便后续打印
                    q.add(next);
                    grid[tx][ty] = 1; // 标记遍历过,避免重复
                }
            } 
        }
        return -1;
    }
    public double distance(int x, int y, int tx, int ty) { // 启发式函数，使用两点距离坐标公式
        return Math.sqrt(Math.pow(tx - x, 2) + Math.pow(ty - y, 2));
    } 
}
*/