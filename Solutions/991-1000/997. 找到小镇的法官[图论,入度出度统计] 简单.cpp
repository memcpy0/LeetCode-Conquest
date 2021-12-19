/*
** Problem: https://leetcode-cn.com/problems/find-the-town-judge/
** Article: https://memcpy0.blog.csdn.net/article/details/109577572
** Author: memcpy0
*/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) { 
        int n = trust.size();
        vector<int> indegrees(N + 1), outdegrees(N + 1); //入度数组
        for (int i = 0; i < n; ++i) {
            ++outdegrees[trust[i][0]];  //a->b, 对于a是出边,对于b是入边
            ++indegrees[trust[i][1]];   //b的入度+1
        }
        for (int i = 1; i <= N; ++i) 
            if (indegrees[i] == N - 1 && outdegrees[i] == 0) //N-1个人都信任他,他不信任任何人
                return i;
        return -1;
    }
};