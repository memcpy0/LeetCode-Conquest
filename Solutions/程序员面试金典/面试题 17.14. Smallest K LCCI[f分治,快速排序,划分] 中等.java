/*
** Problem: https://leetcode-cn.com/problems/smallest-k-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/120108542
** Author: memcpy0
*/
class Solution {
    private int targetK;
    private void swap(int[] arr, int l, int r) {
        int temp = arr[l]; arr[l] = arr[r]; arr[r] = temp;
    }
    private void quickSort(int[] arr, int l, int r) {
        if (l >= r) return;
        int idx = new Random().nextInt(r - l + 1) + l;
        swap(arr, idx, l); //基准值在arr[l]处
        int x = arr[l], i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= x) --j; //改用了>=,效率高一些
            while (i < j && arr[i] <= x) ++i;
            if (i < j) swap(arr, i, j);
        }
        swap(arr, l, i);
        if (i > targetK) quickSort(arr, l, i - 1);
        else if (i < targetK) quickSort(arr, i + 1, r);
    }
    public int[] smallestK(int[] arr, int k) {
        if (k == 0) return new int[k];
        int n = arr.length;
        int[] ans = new int[k];
        targetK = k; //记录k值
        quickSort(arr, 0, n - 1);
        for (int i = 0; i < k; ++i) ans[i] = arr[i];
        return ans;
    }
}