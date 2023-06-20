/*
** Problem: https://leetcode.cn/problems/can-make-palindrome-from-substring/
** Article: https://memcpy0.blog.csdn.net/article/details/131304361
** Author: memcpy0
*/
// BEST: 异或前缀和+位运算+字符串
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> xor_sum(n + 1);
        for (int i = 0; i < n; ++i) // 对应字母的奇偶性:奇数变偶数,偶数变奇数
            xor_sum[i + 1] = xor_sum[i] ^ (1 << (s[i] - 'a')); 
        vector<bool> ans;
        for (vector<int>& q : queries) {
            int l = q[0], r = q[1], k = q[2]; 
            int m = __builtin_popcount(xor_sum[r + 1] ^ xor_sum[l]) - ((r - l + 1) & 1); 
            ans.push_back(m / 2 <= k);
        }
        return ans;
    }
};


class Solution {
public:
   vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
       int n = s.size();
       vector<array<int, 26>> sum(n + 1); // sum[n+1][26]
       for (int i = 0; i < n; ++i) {
           sum[i + 1] = sum[i];
           ++sum[i + 1][s[i] - 'a']; // 计算前缀中每个字母的出现次数
       }
       vector<bool> ans;
       for (vector<int> &q : queries) {
           int l = q[0], r = q[1], k = q[2], m = 0;
           for (int j = 0; j < 26; ++j)
               m += (sum[r + 1][j] - sum[l][j]) % 2; // 奇数+1,偶数+0
           ans.push_back(m / 2 <= k);
       }
       return ans;
   }
};

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<array<int, 26>> sum(n + 1); // sum[n+1][26]
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i];
            ++sum[i + 1][s[i] - 'a']; // 计算前缀中每个字母的奇偶性
            sum[i + 1][s[i] - 'a'] &= 1;
        }
        vector<bool> ans;
        for (vector<int> &q : queries) {
            int l = q[0], r = q[1], k = q[2], m = 0;
            for (int j = 0; j < 26; ++j)
                m += sum[r + 1][j] != sum[l][j];
            ans.push_back(m / 2 <= k);
        }
        return ans;
    }
};

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<array<int, 26>> sum(n + 1); // sum[n+1][26]
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i]; 
            sum[i + 1][s[i] - 'a'] ^= 1; // 奇数次变偶数次,偶数次变奇数次
        }
        vector<bool> ans;
        for (vector<int> &q : queries) {
            int l = q[0], r = q[1], k = q[2], m = 0;
            for (int j = 0; j < 26; ++j)
                m += sum[r + 1][j] ^ sum[l][j];
            ans.push_back(m / 2 <= k);
        }
        return ans;
    }
};
