/*
** Problem: https://leetcode.cn/problems/online-stock-span
** Article: https://memcpy0.blog.csdn.net/article/details/133627004
** Author: memcpy0
*/
class StockSpanner {
private:
    // 单调栈(从栈顶向下单调递减)
    // index动态更新传入的价格下标，维护栈顶为最小的单调递减栈，栈存储<下标,价格>对，
    // 当栈为空(可在栈底预先加入哨兵节点<-1,MAX>避免判断空栈)或栈顶价格大于当前price时将price加入，此时向前的连续递减天数为1(price本身)，
    // 否则弹出价格小于等于当前price的栈顶，剩余栈顶价格就是之前大于当前price的最近元素，两下标相减即price前连续较小天数
    // 若栈内只剩哨兵节点，因为栈是单调递减，说明price之前元素都不大于本身，天数为当期那price下标index+1
    stack<pair<int, int>> st;
    int index = 0;
public:
    StockSpanner() { 
        // 预先在栈底埋入哨兵节点<-1,MAX>，后续不必再特判栈为空的情况
        st.push({INT_MAX, -1});
    }
    
    int next(int price) {
        while (price >= st.top().first) {
            st.pop();
        }
        int ans = index - st.top().second;
        st.push({price, index++});
        return ans;
    }
};