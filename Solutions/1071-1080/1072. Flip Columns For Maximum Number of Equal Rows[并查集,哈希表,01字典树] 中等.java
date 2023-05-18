/*
** Problem: https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/
** Article: https://memcpy0.blog.csdn.net/article/details/130744445
** Author: memcpy0
*/
// 解法1 并查集
class Solution {
    private int find(int[] parent, int p) {
        return parent[p] != p ? parent[p] = find(parent, parent[p]) : parent[p]; 
    }
    private void union(int[] parent, int p, int q) {
        parent[find(parent, p)] = find(parent, q);
    }
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int[] parent = new int[matrix.length];
        for (int i = 0; i < parent.length; ++i) parent[i] = i;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i + 1; j < matrix.length; j++) {
                boolean flag = true;
                for (int k = 0; k < matrix[0].length; k++) {
                    int v = Math.abs(matrix[i][0] - matrix[j][0]);
                    if (Math.abs(matrix[i][k] - matrix[j][k]) != v) {
                        flag = false;
                        break;
                    }
                }
                if (flag) union(parent, i, j);
            }
        }
        int[] cnts = new int[matrix.length];
        for (int i = 0; i < parent.length; i++) {
            find(parent, i);
            cnts[parent[i]]++;
        }
        int ans = 0;
        for (int cnt : cnts) ans = Math.max(ans, cnt); 
        return ans;
    }
}
 
// 解法2 哈希表 
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int ans = 0;
        var rec = new HashMap<String, Integer>();
        for (int i = 0; i < matrix.length; ++i) {
            var key = new StringBuilder();
            var revKey = new StringBuilder();
            // 对key中的0列取反,则key全为1
            // key对应的revKey(相应位置上的值都相反),则相关1列都变为0
            for (int j = 0; j < matrix[i].length; ++j) {
                key.append((char)('0' + matrix[i][j]));
                revKey.append(key.charAt(j) == '0' ? '1' : '0');
            }
            String s = key.toString();
            rec.put(s, rec.getOrDefault(s, 0) + 1);            
            ans = Math.max(ans, rec.get(s) + rec.getOrDefault(revKey.toString(), 0));
        }
        return ans;
    }
} 
// 更优的解法
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int ans = 0, n = matrix[0].length;
        var cnt = new HashMap<String, Integer>();
        for (var row : matrix) {
            var r = new char[n];
            for (int j = 0; j < n; ++j)
                r[j] = (char)(row[j] ^ row[0]); // 翻转第一个数为1的行
            int c = cnt.merge(new String(r), 1, Integer::sum);
            ans = Math.max(ans, c);
        }
        return ans;
    }
}
 
// 解法3 01字典树/二叉树判断
class Solution { 
    private class Node {
        Node left;
        Node right;
        int cnt;
        public Node() { cnt = 0; }
    }
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int ans = 0;
        Node root = new Node();
        for (int[] row : matrix) {
            Node e = root;
            for (int i : row) {
                if (i != row[0]) {
                    if (e.right == null) e.right = new Node();
                    e = e.right;
                } else {
                    if (e.left == null) e.left = new Node();
                    e = e.left;
                }
            }
            ++e.cnt;
            ans = Math.max(ans, e.cnt);
        }
        return ans;
    }
} 