/*
** Problem: https://leetcode.cn/problems/restore-ip-addresses/
** Article: https://memcpy0.blog.csdn.net/article/details/130985442
** Author: memcpy0
*/
class Solution {
private:
    vector<string> ans; 
    void dfs(const string &s, int idx, vector<string>& addrs) {
        if (addrs.size() > 4) return; // 分段超过4个则剪枝
        if (idx >= s.size()) {
            if (addrs.size() == 4) 
                ans.push_back(addrs[0] + "." + addrs[1] + "." + addrs[2] + "." + addrs[3]);
            return;
        }
        for (int len = 1; len <= 3; ++len) {
            if (idx + len > s.size()) break;
            string sa = s.substr(idx, len); 
            if (stoi(sa) > 255 || (sa != "0" && sa[0] == '0')) break;  
            addrs.push_back(sa);
            dfs(s, idx + len, addrs);
            addrs.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return {};
        vector<string> temp;
        dfs(s, 0, temp);
        return ans;
    }
};