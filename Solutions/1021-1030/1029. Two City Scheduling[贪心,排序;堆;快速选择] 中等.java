/*
** Problem: https://leetcode.cn/problems/two-city-scheduling/
** Article: https://memcpy0.blog.csdn.net/article/details/131128594
** Author: memcpy0
*/
// 贪心+排序
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        // sort by a gain which company has by 
        // sending a person to city A and not to city B
        Arrays.sort(costs, (a, b) -> a[0] - a[1] - (b[0] - b[1]));
        int ans = 0, n = costs.length / 2;
        for (int i = 0; i < n; ++i) ans += costs[i][0] + costs[i + n][1];
        return ans;
    }
}
// 贪心+堆
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int n = costs.length, halfN = n >> 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) { 
            ans += costs[i][1]; // 所有人都去b城市的费用总和
            pq.offer(costs[i][0] - costs[i][1]);
            if (pq.size() > halfN) pq.poll();
        }
        while (!pq.isEmpty()) ans += pq.poll(); // +diff
        return ans;
    }
}
// 贪心+堆+优化
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int n = costs.length, halfN = n >> 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) { 
            ans += costs[i][0]; // 所有人都去A市的费用总和
            pq.offer(costs[i][0] - costs[i][1]);
            if (pq.size() > halfN) ans -= pq.poll(); // 弹出的都是不去A市的
        } 
        return ans;
    }
}
// 贪心+快速选择
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int ans = 0, n = costs.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0]; // 都去A市的费用
            arr[i] = costs[i][0] - costs[i][1];
        }
        quickSort(arr, 0, n - 1);
        for (int i = n / 2; i < n; ++i) ans -= arr[i]; // 差价大的,说明去B市更好
        return ans;
    }
    private void quickSort(int[] arr, int l, int r) {
        if (l >= r) return;
        int p = partition(arr, l, r), mid = arr.length / 2;
        if (p == mid) return; // 已经是中点
        if (p > mid) quickSort(arr, l, p - 1);
        else quickSort(arr, p + 1, r);
    } 
    private int partition(int[] arr, int l, int r) {
        int c = l;
        for (int i = l; i < r; ++i)
            if (arr[i] < arr[r]) swap(arr, i, c++);
        swap(arr, r, c);
        return c;
    }
    private void swap(int[] arr, int i, int j) {
        if (i == j) return;
        int swap = arr[i];
        arr[i] = arr[j];
        arr[j] = swap;
    }
}