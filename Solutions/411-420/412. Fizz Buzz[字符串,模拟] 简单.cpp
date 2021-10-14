/*
** Problem: https://leetcode-cn.com/problems/fizz-buzz/
** Article: https://memcpy0.blog.csdn.net/article/details/120756690
** Author: memcpy0
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            bool divBy3 = i % 3 == 0, divBy5 = i % 5 == 0;
            if (divBy3 && divBy5) ans.push_back("FizzBuzz");
            else if (divBy3) ans.push_back("Fizz");
            else if (divBy5) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};