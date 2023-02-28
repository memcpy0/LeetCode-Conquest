/*
** Problem: https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/
** Article: https://memcpy0.blog.csdn.net/article/details/129273456
** Author: memcpy0
*/
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int evenIndexedGreater = 0, oddIndexedGreater = 0; // 表示两种做法下各自需要的move数
        int temp1 = nums[0], temp2 = nums[1];
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (i & 1) { // 让奇数下标位置元素更大,要让两边元素减小
                if (temp1 >= nums[i]) // nums[i-1]已经小于nums[i-2],让它变得更小不影响后面的计数
                    oddIndexedGreater += temp1 - nums[i] + 1;
                if (i + 1 < n) {
                    if (nums[i + 1] >= nums[i]) { // 这里nums[i+1]变动会影响下一个的计数
                        oddIndexedGreater += nums[i + 1] - nums[i] + 1;
                        temp1 = nums[i] - 1;
                    } else temp1 = nums[i + 1];
                }
            } else { // 让偶数下标位置元素更大,要让两边元素减小
                if (i && temp2 >= nums[i])
                    evenIndexedGreater += temp2 - nums[i] + 1;
                if (i + 1 < n) {
                    if (nums[i + 1] >= nums[i]) {
                        evenIndexedGreater += nums[i + 1] - nums[i] + 1;
                        temp2 = nums[i] - 1;
                    } else temp2 = nums[i + 1];
                }
            }
        }
        return min(evenIndexedGreater, oddIndexedGreater);
    }
};