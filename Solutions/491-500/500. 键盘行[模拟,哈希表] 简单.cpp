/*
** Problem: https://leetcode-cn.com/problems/keyboard-row/
** Article: https://memcpy0.blog.csdn.net/article/details/108820492
** Author: memcpy0
*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> board = {
            {'Q', 1}, {'W', 1}, {'E', 1}, {'R', 1}, {'T', 1}, {'Y', 1}, {'U', 1}, {'I', 1}, {'O', 1}, {'P', 1},
            {'A', 2}, {'S', 2}, {'D', 2}, {'F', 2}, {'G', 2}, {'H', 2}, {'J', 2}, {'K', 2}, {'L', 2},
            {'Z', 3}, {'X', 3}, {'C', 3}, {'V', 3}, {'B', 3}, {'N', 3}, {'M', 3}
        };
        vector<string> ans;
        for (const string &word : words) {
            int p1 = board[toupper(word[0])];
            bool flag = true;
            for (int i = 1, n = word.size(); i < n; ++i) {
                int p2 = board[toupper(word[i])];
                if (p1 != p2) {
                    flag = false;
                    break;
                }
                p1 = p2;
            }
            if (flag) ans.push_back(word);
        }
        return ans;
    }
};