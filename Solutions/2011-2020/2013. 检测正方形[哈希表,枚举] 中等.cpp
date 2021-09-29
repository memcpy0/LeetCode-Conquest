/*
** Problem: https://leetcode-cn.com/problems/detect-squares/
** Article: https://memcpy0.blog.csdn.net/article/details/120478693
** Author: memcpy0
*/
class DetectSquares {
private:
    using Key = pair<int, int>;
    struct KeyHash {
        size_t operator()(const Key& k) const {
            return k.first * 10000 + k.second;
        }
    };
    struct KeyEqual {
        bool operator()(const Key& lhs, const Key& rhs) const {
            return lhs.first == rhs.first && lhs.second == rhs.second;
        }
    };
    unordered_map<Key, int, KeyHash, KeyEqual> rec;
    bitset<1010> xs, ys; //查询对应的x,y值是否存在
    int dir[4][2] = {{-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
public:
    DetectSquares() {}
    void add(vector<int> point) { //O(1)
        ++rec[Key{point[0], point[1]}];
        xs[point[0]] = 1;
        ys[point[1]] = 1;
    }
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int lu = min(x, 1000 - y), ru = min(1000 - x, 1000 - y);
        int ld = min(x, y), rd = min(1000 - x, y);
        int lens[4] = {lu, ru, ld, rd};
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= lens[i]; ++j) {
                int dx = x + dir[i][0] * j, dy = y + dir[i][1] * j;
                if (xs[dx] == 0 || ys[dy] == 0) continue;
                Key p1 = Key{dx, y};
                Key p2 = Key{dx, dy};
                Key p3 = Key{x, dy};
                ans += rec[p1] * rec[p2] * rec[p3];  
            }
        }
        return ans;
    }
}; 