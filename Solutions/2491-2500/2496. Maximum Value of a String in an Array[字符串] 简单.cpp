/*
** Problem: https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/
** Article: https://memcpy0.blog.csdn.net/article/details/131359056
** Author: memcpy0
*/
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0; 
        for (auto &str : strs) {
            bool isDigits = true; 
            for (const char &c : str) isDigits &= isdigit(c);
            ans = max(ans, isDigits ? stoi(str) : (int)str.size());
        }
        return ans;
    }
};