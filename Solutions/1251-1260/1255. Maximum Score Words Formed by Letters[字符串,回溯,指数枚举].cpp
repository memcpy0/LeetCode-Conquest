/*
** Problem: https://leetcode.cn/problems/maximum-score-words-formed-by-letters/
** Article: https://memcpy0.blog.csdn.net/article/details/129273445
** Author: memcpy0
*/
class Solution {
private:
    int maxScore = INT_MIN;
    unordered_map<string, int> wordToScore;
    vector<string> valids;
    void dfs(int i, unordered_map<char, int> ltt, int tscore) {
        if (i >= valids.size()) {
            if (tscore > maxScore) maxScore = tscore;
            return;
        }
        unordered_map<char, int> temp;        
        for (const char &c : valids[i]) ++temp[c];  
        bool flag = true;      
        for (auto &it : temp) {
            if (it.second > ltt[it.first]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (auto &it : temp) ltt[it.first] -= it.second;
            dfs(i + 1, ltt, tscore + wordToScore[valids[i]]);
            for (auto &it : temp) ltt[it.first] += it.second;
        }
        dfs(i + 1, ltt, tscore);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letterToTimes;
        for (const char &c : letters) ++letterToTimes[c];
        for (const string& word : words) {
            unordered_map<char, int> temp;
            int wscore = 0;
            bool flag = true;
            for (const char &c : word) {
                ++temp[c];    
                wscore += score[c - 'a'];
                if (temp[c] > letterToTimes[c]) {
                    flag = false;
                    break;
                }
            }  
            if (flag) {
                valids.push_back(word);
                wordToScore[word] = wscore;
            }
        }
        dfs(0, letterToTimes, 0);
        return maxScore;
    }
};
