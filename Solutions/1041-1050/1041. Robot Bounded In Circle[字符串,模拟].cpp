/*
** Problem: https://leetcode.cn/problems/robot-bounded-in-circle/
** Article: https://memcpy0.blog.csdn.net/article/details/130082777
** Author: memcpy0
*/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, dir = 0; // 0北,1东,2南,3西
        for (char &c : instructions) {
            if (c == 'G') x += move[dir][0], y += move[dir][1];
            else if (c == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};