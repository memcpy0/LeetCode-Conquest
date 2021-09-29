/*
** Problem: https://leetcode-cn.com/problems/detect-squares/
** Article: https://memcpy0.blog.csdn.net/article/details/120478693
** Author: memcpy0
*/
class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> rec;
    unordered_map<int, unordered_set<int>> row; //存储所有在同一垂直线的点的纵坐标
public:
    DetectSquares() {}
    void add(vector<int> point) { //O(1)
        ++rec[point[0]][point[1]];
        row[point[0]].insert(point[1]);
    }
    int count(vector<int> point) {
        int x = point[0], y = point[1], ans = 0;
        for (const auto &v : row[x]) { //遍历与x处于同一垂直线的所有点v
            if (v == y) continue; //同一点,跳过
            int len = abs(y - v); //以y到v的距离作为正方形的边长len
            ans += rec[x][v] * rec[x + len][v] * rec[x + len][y]; //作为左边时
            ans += rec[x][v] * rec[x - len][v] * rec[x - len][y]; //作为右边时
        }
        return ans;
    }
}; 