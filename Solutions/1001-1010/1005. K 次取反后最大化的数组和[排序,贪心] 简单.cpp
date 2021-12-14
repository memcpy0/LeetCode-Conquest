/*
** Problem: https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
** Article: https://memcpy0.blog.csdn.net/article/details/121940697
** Author: memcpy0
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int sum = 0, minval = INT_MAX;
        for (int i = 0, n = A.size(); i < n; ++i) {
            int val = A[i];
            if (val < 0 && K > 0) { // 按照负数从小到大的顺序进行取反
                --K;
                val = -val;
            }
            sum += val; // 计算数组总和(元素可能取反或未取反)
            minval = min(minval, val); // 记录进行全部的取反操作后,数组的最小值
        }
        if (K > 0 && (K & 1))   // 还有取反次数,且为奇数次(偶数次反转后还是原数,不需要考虑)
            sum -= 2 * minval;  // 减去2倍的最小值 
        return sum;
    }
};