/*
** Problem: https://leetcode.cn/problems/find-in-mountain-array
** Article: https://memcpy0.blog.csdn.net/article/details/133848544
** Author: memcpy0
*/
// BEST: key函数复用二分
class Solution {
private:
    int binarySearch(MountainArray &mountain, int target, int l, int r, int key(int)) {
        target = key(target);
        while (l <= r) {
            int m = l + r >> 1;
            int cur = key(mountain.get(m));
            if (cur == target) return m;
            else if (cur < target) l = m + 1;
            else r = m - 1; 
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        while (l < r) {
            int m = l + r >> 1;
            if (mountainArr.get(m) < mountainArr.get(m + 1)) l = m + 1; // 在右边
            else r = m;
        }
        int peak = l;
        int index = binarySearch(mountainArr, target, 0, peak, 
            [](int x) -> int { return x; });
        if (index != -1) return index;
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, 
            [](int x) -> int { return -x; });
    }
};