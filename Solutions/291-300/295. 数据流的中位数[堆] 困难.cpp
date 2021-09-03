/*
** Problem: https://leetcode-cn.com/problems/find-median-from-data-stream/
** Article: https://memcpy0.blog.csdn.net/article/details/120076311
** Author: memcpy0
*/
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> left; //大根堆
    priority_queue<int, vector<int>, greater<int>> right; //小根堆
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    /* left维护序列的左半部分,right维护右半部分
    ** 0 <= left.size() - right.size() <= 1
    ** 左右两堆大小相等时,加入新的数,数据流长度为奇数,取中位数就取left.top()
    **   - 都为空(右堆空)时,直接加入left堆
    **   - 都不为空时:
    **       - 如果num<=right.top(),应该放入left堆
    **       - 如果num>right.top(),应该取出right.top()放入left堆,将num放入right堆
    ** 左右两堆大小差1时(左>右),加入新的数,数据流长度为偶数,
    ** 取中位数就取(left.top()+right.top())/2.0
    **   - 如果num>=left.top(),应该放入right堆
    **   - 如果num<left.top(),应该取出left.top()放入right堆,将num放入left堆
    */
    void addNum(int num) {
        if (left.size() == right.size()) {
            if (right.empty() || num <= right.top()) left.push(num);
            else {
                left.push(right.top()); right.pop();
                right.push(num);
            }
        } else {
            if (num >= left.top()) right.push(num);
            else {
                right.push(left.top()); left.pop();
                left.push(num);
            }
        }
    }
    double findMedian() {
        return left.size() == right.size() ? 
                ((left.top() + right.top()) / 2.0) : left.top();
    }
};