/*
** Problem: https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/
** Article: https://memcpy0.blog.csdn.net/article/details/130737945
** Author: memcpy0
*/
// 反向思考
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[1] < event2[0] || event2[1] < event1[0]);
    }
};
// 正向思考
class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        return event1[0].compareTo(event2[1]) <= 0 && event2[0].compareTo(event1[1]) <= 0;
    }
}