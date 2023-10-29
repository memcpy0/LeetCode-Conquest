/*
** Problem: https://leetcode.cn/problems/valid-parentheses/
** Article: https://memcpy0.blog.csdn.net/article/details/108015888
** Author: memcpy0
*/
// BEST
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        if (s.size() & 1) return false; // 奇数长度优化
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && (c - st.top() == 1 || c - st.top() == 2)) st.pop(); // (+1=),{+2=},[+2=]
            else st.push(c);
        }
        return st.empty();
    }
};
// 初版
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m[')'] = '(', m[']'] = '[', m['}'] = '{';
        stack<char> st;
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else {
                if (st.empty() || st.top() != m[s[i]]) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};