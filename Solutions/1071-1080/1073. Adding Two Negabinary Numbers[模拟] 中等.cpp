/*
** Problem: https://leetcode.cn/problems/adding-two-negabinary-numbers/
** Article: https://memcpy0.blog.csdn.net/article/details/130774789
** Author: memcpy0
*/
class Solution { 
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        int carry = 0;
        vector<int> ans;
        while (i >= 0 || j >= 0 || carry) {
            int x = carry;
            if (i >= 0) x += arr1[i];
            if (j >= 0) x += arr2[j];
            if (x >= 2) { // 逢2进-1
                ans.push_back(x - 2);
                carry = -1;
            } else if (x >= 0) {
                ans.push_back(x);
                carry = 0;
            } else { // x = -1
                ans.push_back(1);
                carry = 1;
            }
            --i, --j;
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};