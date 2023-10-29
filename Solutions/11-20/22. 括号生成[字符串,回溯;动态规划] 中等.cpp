/*
** Problem: https://leetcode.cn/problems/generate-parentheses/
** Article: https://memcpy0.blog.csdn.net/article/details/134002642
** Author: memcpy0
*/
// 暴力DFS,2^{2n}个序列
class Solution {
private:
    vector<string> ans;
    bool valid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') ++balance;
            else --balance;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    void dfs(string& s, int n) {
        if (n == s.size()) {
            if (valid(s)) ans.push_back(s); // 检查是否有效序列
            return;
        }
        s += '(';
        dfs(s, n);
        s.pop_back();
        s += ')';
        dfs(s, n);
        s.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string current;
        dfs(current, n * 2);
        return ans;
    }
};
// 提前判断是否有效,有效才添加
class Solution {
private:
    vector<string> ans;
    void dfs(string& s, int n, int open, int close) {
        if (n == s.size()) {
            ans.push_back(s);
            return;
        }
        if (open * 2 < n) { // 剩余左括号数>0,放个左括号
            s += '(';
            dfs(s, n, open + 1, close);
            s.pop_back();
        }
        if (close < open) { // 0<剩余左括号数<剩余右括号数,可放左括号(前面),也可放右括号(这里)
            s += ')';
            dfs(s, n, open, close + 1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string current;
        dfs(current, n * 2, 0, 0);
        return ans;
    }
};
// BEST:写法最简,上面的简写版
class Solution {
private:
    vector<string> ans;
    void dfs(const string& s, int l, int r) {
        if (l == 0 && r == 0) {
            ans.push_back(s);
            return;
        }
        if (l > 0) dfs(s + '(', l - 1, r);
        if (l < r) dfs(s + ')', l, r - 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return ans;
    }
};
// 记忆化搜索,先搜索a个括号的序列,再搜索b个括号的序列,a+b=n-1,f(n)=(a)b
class Solution {
private:
    shared_ptr<vector<string>> cache[100] = {nullptr}; // string[][]
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr) return cache[n];
        if (n == 0) 
            cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts)
                    for (const string& right : *rights)
                        result -> push_back("(" + left + ")" + right);
            }
            cache[n] = result;
        }
        return cache[n];
    }
public:
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};
// 动态规划,先找一个括号的所有序列,然后是两个括号的……
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return {};
		if (n == 1) return { "()" };
		vector<vector<string>> dp(n + 1);
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int parenthesisNum = 2; parenthesisNum <= n; ++parenthesisNum) {
			for (int i = 0; i < parenthesisNum; ++i) {
                int j = parenthesisNum - i - 1;
				for (string &a : dp[i])
					for (string &b : dp[j]) 
						dp[parenthesisNum].push_back("(" + a + ")" + b);
			}
		}
		return dp[n];
	}
};