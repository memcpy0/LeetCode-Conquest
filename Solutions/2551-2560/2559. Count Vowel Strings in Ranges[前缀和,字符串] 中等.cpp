/*
** Problem: https://leetcode.cn/problems/count-vowel-strings-in-ranges/
** Article: https://memcpy0.blog.csdn.net/article/details/131046346
** Author: memcpy0
*/
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
       function<bool(char)> is_vowel = [&](char c) { 
           return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
       };
       vector<int> sum;
       sum.push_back(0);
       for (string word : words)
           sum.push_back(sum.back() + (is_vowel(word[0]) && is_vowel(word.back())));
       vector<int> ans;
       for (vector<int> &q : queries)
           ans.push_back(sum[q[1] + 1] - sum[q[0]]);
       return ans;
    }
};