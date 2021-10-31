/*
** Problem: https://leetcode-cn.com/problems/single-number/
** Article: https://memcpy0.blog.csdn.net/article/details/106988806
** Author: memcpy0
*/
int singleNumber(int* nums, int numsSize) {
    int ans = 0, n = (numsSize + 7) / 8;
    switch (numsSize % 8) {
        case 0: do { ans ^= *nums++;
        case 7:      ans ^= *nums++;
        case 6:      ans ^= *nums++;
        case 5:      ans ^= *nums++;
        case 4:      ans ^= *nums++;
        case 3:      ans ^= *nums++;
        case 2:      ans ^= *nums++;
        case 1:      ans ^= *nums++;
                } while (--n > 0);
    }
    return ans;
}