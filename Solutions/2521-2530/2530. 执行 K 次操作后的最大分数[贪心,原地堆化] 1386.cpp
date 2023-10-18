/*
** Problem: https://leetcode.cn/problems/maximal-score-after-applying-k-operations/
** Article: https://memcpy0.blog.csdn.net/article/details/133900018
** Author: memcpy0
*/
// BEST
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end()); // 原地堆化(最大堆)
        long long ans = 0;
        while (k--) {
            pop_heap(nums.begin(), nums.end()); // 把堆顶移到末尾
            ans += nums.back();
            nums.back() = (nums.back() + 2) / 3;
            push_heap(nums.begin(), nums.end()); // 把末尾元素入堆
        }
        return ans;
    }
};
// 原地堆化实现
class Solution {
    public long maxKelements(int[] nums, int k) {
        heapify(nums); // 原地堆化(最大堆)
        long ans = 0;
        while (k-- > 0) {
            ans += nums[0]; // 堆顶
            nums[0] = (nums[0] + 2) / 3;
            sink(nums, 0); // 堆化(只要把nums[0]下沉即可)
        }
        return ans;
    }
    // 原地堆化（最大堆）
    // 堆化可以保证 h[0] 是堆顶元素，且 h[i] >= max(h[2*i+1], h[2*i+2])
    private void heapify(int[] h) {
        // 下标 >= h.length / 2 的元素是二叉树的叶子，无需下沉
        // 倒着遍历，从而保证 i 的左右子树一定是堆，那么 sink(h, i) 就可以把左右子树合并成一个堆
        for (int i = h.length / 2 - 1; i >= 0; i--)
            sink(h, i);
    }
    // 把 h[i] 不断下沉，直到 i 的左右儿子都 <= h[i]
    private void sink(int[] h, int i) {
        int n = h.length;
        while (2 * i + 1 < n) {
            int j = 2 * i + 1; // i的左儿子
            if (j + 1 < n && h[j + 1] > h[j]) // i的右儿子比左儿子大
                ++j;
            if (h[j] <= h[i]) // 说明i的左右儿子都<=h[i],停止下沉
                break;
            swap(h, i, j); // 下沉
            i = j;
        }
    }
    // 交换h[i]和h[j]
    private void swap(int[] h, int i, int j) {
        int tmp = h[i];
        h[i] = h[j];
        h[j] = tmp;
    }
}