/*
** Problem: https://leetcode.cn/problems/design-front-middle-back-queue/
** Article: https://memcpy0.blog.csdn.net/article/details/133851499
** Author: memcpy0
*/
// BEST
class FrontMiddleBackQueue {
    private Deque<Integer> left, right; // left的大小等于或比right少1个元素
    private void reBalance() {
        if (left.size() > right.size()) 
            right.addFirst(left.pollLast());
        else if (left.size() + 1 < right.size())
            left.addLast(right.pollFirst());
    }
    public FrontMiddleBackQueue() {
        left = new ArrayDeque<>();
        right = new ArrayDeque<>();
    }
    
    public void pushFront(int val) {
        left.addFirst(val);
        reBalance();
    }
    
    public void pushMiddle(int val) {
        if (left.size() == right.size()) right.addFirst(val);
        else left.addLast(val);
    }
    
    public void pushBack(int val) {
        right.addLast(val);
        reBalance();
    }
    
    public int popFront() {
        Integer ans = left.pollFirst();
        if (ans == null) {
            ans = right.pollFirst();
            return ans == null ? -1 : ans;
        } else {
            reBalance();
            return ans;
        }
    }
    
    public int popMiddle() {
        if (left.size() == right.size()) {
            Integer ans = left.pollLast();
            return ans == null ? -1 : ans;
        } else return right.pollFirst();
    }
    
    public int popBack() {
        Integer ans = right.pollLast();
        reBalance();
        return ans == null ? -1 : ans;
    }
}