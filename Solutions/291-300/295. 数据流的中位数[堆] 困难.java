/*
** Problem: https://leetcode-cn.com/problems/find-median-from-data-stream/
** Article: https://memcpy0.blog.csdn.net/article/details/120076311
** Author: memcpy0
*/
class MedianFinder {
    private PriorityQueue<Integer> left = new PriorityQueue<>((a, b) -> b - a);
    private PriorityQueue<Integer> right = new PriorityQueue<>((a, b) -> a - b);
    /** initialize your data structure here. */
    public MedianFinder() {}
    
    public void addNum(int num) {
        if (left.size() == right.size()) {
            if (right.isEmpty() || num <= right.peek()) {
                left.add(num);
            } else {
                left.add(right.poll());
                right.add(num);
            } 
        } else {
            if (num >= left.peek()) {
                right.add(num);
            } else {
                right.add(left.poll());
                left.add(num);
            }
        }
    }
    
    public double findMedian() {
        if (left.size() == right.size()) return (left.peek() + right.peek()) / 2.0;
        else return left.peek();
    }
}