/*
** Problem: https://leetcode.cn/problems/next-greater-node-in-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/130071504
** Author: memcpy0
*/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {  
        vector<int> vals; // 记录原数组的值,随后vals[i]被赋值为大于它的第一个值
        stack<int> pos; // 单调栈,只存下标 
        while (head) {
            while (!pos.empty() && head->val > vals[pos.top()] ) { // 这里的vals代表原数组
                vals[pos.top()] = head->val; // 被赋值为大于它的第一个值,且之后不会被修改和访问
                pos.pop();
            }
            pos.push(vals.size()); // 当前ans的长度就是当前节点的下标
            vals.push_back(head->val);
            head = head->next;
        }
        while (!pos.empty()) vals[pos.top()] = 0, pos.pop(); // 剩下的就是没有下一个更大值的下标位置
        return vals;
    }
};

/*
// Java代码,从右到左
class Solution {
    private int[] ans;
    private final Deque<Integer> st = new ArrayDeque<>(); // 单调栈(节点值)
    private void f(ListNode node, int i) {
        if (node == null) {
            ans = new int[i]; // i就是链表长度
            return;
        }
        f(node.next, i + 1);
        while (!st.isEmpty() && st.peek() <= node.val)
            st.pop(); // 弹出无用数据
        if (!st.isEmpty()) ans[i] = st.peek(); // 栈顶就是第i个节点的下个更大元素
        st.push(node.val);
    }
    public int[] nextLargerNodes(ListNode head) {
        f(head, 0); 
        return ans;
    }
}
*/