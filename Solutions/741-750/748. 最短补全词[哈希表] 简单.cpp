/*
** Problem: https://leetcode-cn.com/problems/shortest-completing-word/
** Article: https://memcpy0.blog.csdn.net/article/details/108890484
** Author: memcpy0
*/
class Solution {
private:
    int scnt[26], cnt[26];
    bool check(const string &s) {
        memset(scnt, 0, sizeof(scnt));
        for (const char &c : s) ++scnt[c - 'a'];
        for (int i = 0; i < 26; ++i) 
            if (cnt[i] > scnt[i]) return false;
        return true; 
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        for (const char &c : licensePlate) 
            if (isalpha(c)) ++cnt[tolower(c) - 'a'];
        int minLen = INT_MAX, idx = 0;
        for (int i = 0, wordLen = words.size(); i < wordLen; ++i) {
            if (check(words[i])) { //检查是否补全词
                if (words[i].size() < minLen) {
                    minLen = words[i].size();
                    idx = i;
                }
            }
        }
        return words[idx];
    }
};