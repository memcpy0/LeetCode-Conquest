/*
** Problem: https://leetcode.cn/problems/split-two-strings-to-make-palindrome/
** Article: https://memcpy0.blog.csdn.net/article/details/129642730
** Author: memcpy0
*/
// 贪心+相向双指针
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        function<bool(string, int, int)> isPalindrome = [&](const string &x, int l, int r) {
            while (l < r && x[l] == x[r]) ++l, --r;
            return l >= r;
        };
        // 双指针判断x的前缀和y的后缀是否组成回文
        function<bool(string, string)> check = [&](const string &x, const string &y) {
            for (int i = 0, j = y.size() - 1; i < j; ++i, --j) { // 相向双指针
                // x从前往后,与y从后往前对比,前后缀尽量匹配
                // ulac cfd , ula ccfd
                // zjiz alu , zji zalu
                if (x[i] != y[j]) { // 字符x[i]和y[j]不等,要组成回文
                    // 可能从i前分割开,于是要看y[i:j]是否回文
                    // 或者从j后分割开,于是要看x[i:j]是否回文
                    return isPalindrome(y, i, j) || isPalindrome(x, i, j);
                }
            }
            return true;
        };
        return check(a, b) || check(b, a); 
    }
}; 
// 中心扩展+相反双指针
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        function<int(string, string, int)> check = [&](const string &x, const string& y, int left) {
            int right = n - left - 1;
            while (left >= 0 && right < n && x[left] == y[right]) --left, ++right;
            return left;
        };
        int left = n / 2 - 1; // 中心位置
        left = min(check(a, a, left), check(b, b, left));
        left = min(check(a, b, left), check(b, a, left));
        return left == -1;
    }
}