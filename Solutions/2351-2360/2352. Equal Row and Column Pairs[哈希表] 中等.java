/*
** Problem: https://leetcode.cn/problems/equal-row-and-column-pairs/
** Article: https://memcpy0.blog.csdn.net/article/details/131105914
** Author: memcpy0
*/
class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        var cnt = new HashMap<List<Integer>, Integer>();
        for (int[] row : grid) {
            List<Integer> arr = new ArrayList<Integer>();
            for (int num : row) arr.add(num);
            cnt.put(arr, cnt.getOrDefault(arr, 0) + 1);
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            var arr = new ArrayList<Integer>();
            for (int i = 0; i < n; ++i) arr.add(grid[i][j]);
            ans += cnt.getOrDefault(arr, 0);
        }
        return ans;
    }
}