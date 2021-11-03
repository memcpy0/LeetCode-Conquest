/*
** Problem: https://leetcode-cn.com/problems/repeated-dna-sequences/
** Article: https://memcpy0.blog.csdn.net/article/details/120662605
** Author: memcpy0
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> rec;
        vector<string> ans;
        for (int i = 0, n = s.size(); i + 10 <= n; ++i) {
            string &&cur = s.substr(i, 10); // 使用右值引用避免不必要的拷贝赋值调用
            int &cnt = rec[cur]; //节省再次查找的时间
            if (cnt == 1) ans.push_back(cur);
            ++cnt;
        } 
        return ans;
    }
};