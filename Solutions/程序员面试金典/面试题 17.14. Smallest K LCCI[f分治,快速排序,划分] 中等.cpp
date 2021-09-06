/*
** Problem: https://leetcode-cn.com/problems/smallest-k-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/120108542
** Author: memcpy0
*/
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
class Solution {
private:
    int targetK;
    uniform_int_distribution<int> ud;
    void quickSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        ud.param(uniform_int_distribution<>::param_type {l, r});
        int idx = ud(generator);
        swap(arr[l], arr[idx]);
        int x = arr[l], i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= x) --j;
            while (i < j && arr[i] <= x) ++i;
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[i]);
        if (i > targetK) quickSort(arr, l, i - 1);
        else if (i < targetK) quickSort(arr, i + 1, r);
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) return {}; //注意k=0时,需要直接返回{}
        vector<int> ans;
        targetK = k;
        quickSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < k; ++i) ans.push_back(arr[i]);
        return ans;
    }
};