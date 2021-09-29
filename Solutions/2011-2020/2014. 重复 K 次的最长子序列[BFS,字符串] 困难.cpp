/*
** Problem: https://leetcode-cn.com/problems/longest-subsequence-repeated-k-times/
** Article: https://memcpy0.blog.csdn.net/article/details/120557243
** Author: memcpy0
*/
class Solution {
private:
    int checkCount(const string &sub, const string &s) {
        int n = sub.size(), m = s.size(), i = 0, j = 0, cnt = 0;
        while (j < m) {
            if (sub[i] == s[j]) {
                ++i;
                if (i == n) ++cnt, i = 0;
            }
            ++j;
        }
        return cnt;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        if (n < k) return ""; //n个字符不足以让一个子序列重复k次
        queue<string> q; q.push("");
        string ans;
        while (!q.empty()) {
            string p = q.front(); q.pop();
            ans = p; //p是更长的、字典序更大的，重复k次的子序列
            for (char c = 'a'; c <= 'z'; ++c) {
                //从a加到z,保证队列中的数据一定按照字典序、且长度非递减排列
                string t = p + c;
                if (checkCount(t, s) >= k) q.push(t);
            }
        }
        return ans;
    }
};