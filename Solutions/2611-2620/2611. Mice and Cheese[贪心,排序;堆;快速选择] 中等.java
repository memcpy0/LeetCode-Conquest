/*
** Problem: https://leetcode.cn/problems/mice-and-cheese/
** Article: https://memcpy0.blog.csdn.net/article/details/131128336
** Author: memcpy0
*/

// 贪心+排序
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int ans = 0, n = reward1.length;
        int[] diffs = new int[n];
        for (int i = 0; i < n; ++i) {
            ans += reward2[i];
            diffs[i] = reward1[i] - reward2[i];
        }
        Arrays.sort(diffs);
        for (int i = 1; i <= k; ++i) ans += diffs[n - i];
        return ans;
    }
}

// 贪心+小顶堆
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // 默认小顶堆
        int n = reward1.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) { 
            ans += reward2[i]; // 老鼠2吃掉所有奶酪的总分
            pq.offer(reward1[i] - reward2[i]);
            if (pq.size() > k) pq.poll();
        }
        while (!pq.isEmpty()) ans += pq.poll(); // +diff=+reward1[i]-reward2[i]
        return ans;
    }
}
// 贪心+小顶堆+优化
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // 默认小顶堆
        int n = reward1.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) { 
            ans += reward1[i]; // 老鼠1吃掉所有奶酪的总分
            pq.offer(reward1[i] - reward2[i]);
            if (pq.size() > k) ans -= pq.poll(); // 从堆中出来,说明不是老鼠1吃的
        } 
        return ans;
    }
}

// 贪心+快速选择
class Solution {
    private int pos;
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int n = reward1.length, ans = 0;
        int[] arr = new int[n];
        pos = n - k; // 前n-k个分差小的奶酪
        for (int i = 0; i < n; ++i) { 
            ans += reward1[i]; // 老鼠1吃掉所有奶酪的总分
            arr[i] = reward1[i] - reward2[i];
        } 
        quickSort(arr, 0, n - 1);
        for (int i = 0; i < pos; ++i) ans -= arr[i]; // 前n-k个应该由老鼠2吃掉
        return ans;
    }
    private void quickSort(int[] arr, int l, int r) {
        if (l >= r) return;
        int p = partition(arr, l, r);
        if (p == pos || p == pos - 1) return;
        else if (p > pos) quickSort(arr, l, p - 1);
        else quickSort(arr, p + 1, r);
    }
    private int partition(int[] arr, int l, int r) {
        int c = l;
        for (int i = l; i < r; ++i) 
            if (arr[i] < arr[r])
                swap(arr, i, c++);
        swap(arr, r, c);
        return c;
    }
    private void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

// C++中的快速选择(最优)
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size(); 
        for (int i = 0; i < n; ++i) reward1[i] -= reward2[i]; // 原地修改
        nth_element(reward1.begin(), reward1.end() - k, reward1.end()); // 快速选择
        return accumulate(reward2.begin(), reward2.end(), 0) + // 先全部给第2只老鼠
            accumulate(reward1.end() - k, reward1.end(), 0); // 再加上增量 
    }
};