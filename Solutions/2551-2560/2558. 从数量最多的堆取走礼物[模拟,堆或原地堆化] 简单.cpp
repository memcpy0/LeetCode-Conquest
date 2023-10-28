/*
** Problem: https://leetcode.cn/problems/take-gifts-from-the-richest-pile/
** Article: https://memcpy0.blog.csdn.net/article/details/134089409
** Author: memcpy0
*/
// 堆
class Solution {
    public long pickGifts(int[] gifts, int k) {
        var pq = new PriorityQueue<Integer>(gifts.length, (Integer a, Integer b) -> {
            return b- a;
        });
        for (int gift : gifts) pq.add(gift);
        for (int i = 0; i < k; ++i) {
            long m = pq.poll();
            pq.add((int) Math.sqrt(m)); // 留下平方根数量的礼物
        }
        long ans = 0;
        while (!pq.isEmpty()) ans += pq.poll();
        return ans;
    }
} 
// 原地堆化:O(1)空间
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end()); // 原地堆化,最大堆
        while (k-- && gifts[0] > 1) {
            pop_heap(gifts.begin(), gifts.end()); // 弹出堆顶并移到末尾
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end()); // 把末尾元素入堆
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};