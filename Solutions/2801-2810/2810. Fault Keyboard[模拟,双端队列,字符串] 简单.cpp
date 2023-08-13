/*
** Problem: https://leetcode.cn/problems/faulty-keyboard/
** Article: https://memcpy0.blog.csdn.net/article/details/132249709
** Author: memcpy0
*/
// BEST: 双端队列
class Solution {
public:
    string finalString(string s) {
        deque<char> dq;
        bool last = true;
        for (char c : s) {
            if (c == 'i') last = !last;
            else if (last) dq.push_back(c);
            else dq.push_front(c);
        }
        return last ? string(dq.begin(), dq.end()) : string(dq.rbegin(), dq.rend());
    }
};