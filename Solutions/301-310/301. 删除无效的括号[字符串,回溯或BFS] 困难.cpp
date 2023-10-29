/*
** Problem: https://leetcode.cn/problems/remove-invalid-parentheses/
** Article: https://memcpy0.blog.csdn.net/article/details/134111221
** Author: memcpy0
*/
// 遍历下个删除位置+剪枝+跳过连续重复括号去重
class Solution {
public:
    vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0, rremove = 0; // 左括号和右括号最少应被删除的数量
        for (char c : s) {
            if (c == '(') ++lremove;
            else if (c == ')') {
                if (lremove == 0) ++rremove;
                else --lremove; // 左右括号匹配
            }
        }
        dfs(s, 0, lremove, rremove);
        return ans;
    }
    void dfs(const string &s, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (valid(s)) ans.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (i != start && s[i] == s[i - 1]) continue;
            // 如果剩余的字符无法满足去掉的数量要求，直接返回
            if (lremove + rremove > s.size() - i) return; // 剩余未尝试的字符串长度较小，无法继续
            // 尝试去掉一个左括号
            if (lremove > 0 && s[i] == '(')
                dfs(s.substr(0, i) + s.substr(i + 1), i, lremove - 1, rremove); // 注意下个开始的下标还是i
            // 尝试去掉一个右括号
            if (rremove > 0 && s[i] == ')')
                dfs(s.substr(0, i) + s.substr(i + 1), i, lremove, rremove - 1);
        }
    }
    inline bool valid(const string &s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') ++cnt;
            else if (c == ')') { // 有括号以外的字符
                --cnt;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
};
// 当前删或不删+哈希表去重
class Solution {
public:
    unordered_set<string> st;
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0, rremove = 0; // 左括号和右括号最少应被删除的数量
        for (char c : s) {
            if (c == '(') ++lremove;
            else if (c == ')') {
                if (lremove == 0) ++rremove;
                else --lremove;
            }
        }
        dfs(s, 0, lremove, rremove);
        return vector<string>(st.begin(), st.end());
    }
    void dfs(const string &s, int i, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (valid(s)) st.insert(s);
            return;
        }
        // 还需要删除的括号个数 > 能够删除的字符个数
        if (lremove + rremove > s.size() - i) return;
        // 不删除
        dfs(s, i + 1, lremove, rremove);
        // 删除,分左右括号考虑
        // 尝试去掉一个左括号
        if (lremove > 0 && s[i] == '(')
            dfs(s.substr(0, i) + s.substr(i + 1), i, lremove - 1, rremove);
        // 尝试去掉一个右括号
        if (rremove > 0 && s[i] == ')')
            dfs(s.substr(0, i) + s.substr(i + 1), i, lremove, rremove - 1);
    }
    inline bool valid(const string &s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') ++cnt;
            else if (c == ')') { // 有括号以外的字符
                --cnt;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
};
// BFS
class Solution {
public:
    unordered_set<string> curSet;
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        curSet.insert(s);
        while (true) {
            for (auto &str : curSet) if (valid(str)) ans.emplace_back(str);
            if (ans.size() > 0) return ans; // BFS,删除括号最少的合法字符串
            unordered_set<string> nextSet;
            for (auto &str : curSet) {
                for (int i = 0; i < str.size(); ++i) {
                    if (i > 0 && str[i] == str[i - 1]) continue; // 对当前连续重复的括号只需删除一个
                    if (str[i] == '('  || str[i] == ')') // 第k步迭代,删除第k个括号
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
                }
            }
            curSet = nextSet;
        }
    }
    inline bool valid(const string &s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') ++cnt;
            else if (c == ')') { // 有括号以外的字符
                --cnt;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
};
// 枚举删除左括号或右括号的状态子集并组合
class Solution {
public:
    bool checkValid(const string & str, int lmask, vector<int> & left, int rmask, vector<int> & right) {
        int pos1 = 0;
        int pos2 = 0;
        int cnt = 0;

        for (int i = 0; i < str.size(); i++) {
            if (pos1 < left.size() && i == left[pos1]) {
                if (!(lmask & (1 << pos1))) {
                    cnt++;
                }
                pos1++;
            } else if (pos2 < right.size() && i == right[pos2]) {
                if (!(rmask & (1 << pos2))) {
                    cnt--;
                    if (cnt < 0) {
                        return false;
                    }
                }
                pos2++;
            }
        }

        return cnt == 0;
    }

    string recoverStr(const string & str, int lmask, vector<int> & left, int rmask, vector<int> & right){
        string ans;
        int pos1 = 0;
        int pos2 = 0;

        for (int i = 0; i < str.size(); i++) {
            if (pos1 < left.size() && i == left[pos1]) {
                if (!(lmask & (1 << pos1))){
                    ans.push_back(str[i]);
                }
                pos1++;
            } else if (pos2 < right.size() && i == right[pos2]) {
                if (!(rmask & (1 << pos2))) {
                    ans.push_back(str[i]);
                }
                pos2++;
            } else {
                ans.push_back(str[i]);
            }
        }

        return ans;
    }

    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0;
        int rremove = 0;
        vector<int> left;
        vector<int> right;
        vector<string> ans;
        unordered_set<string> cnt;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push_back(i);
                lremove++;
            } else if (s[i] == ')') {
                right.push_back(i);
                if (lremove == 0) {
                    rremove++;
                } else {
                    lremove--;
                }
            }
        }

        int m = left.size();
        int n = right.size();
        vector<int> maskArr1;
        vector<int> maskArr2;
        for (int i = 0; i < (1 << m); i++) {
            if (__builtin_popcount(i) != lremove) {
                continue;
            }
            maskArr1.push_back(i);
        }
        for (int j = 0; j < (1 << n); j++) {
            if (__builtin_popcount(j) != rremove) {
                continue;
            }
            maskArr2.push_back(j);
        }
        for (auto mask1 : maskArr1) {
            for (auto mask2 : maskArr2) {
                if (checkValid(s, mask1, left, mask2, right)) {
                    cnt.insert(recoverStr(s, mask1, left, mask2, right));
                }
            }
        }
        for (auto v : cnt) {
            ans.emplace_back(v);
        }

        return ans;
    }
};