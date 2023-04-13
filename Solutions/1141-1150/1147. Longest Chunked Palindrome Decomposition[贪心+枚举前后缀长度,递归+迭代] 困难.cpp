/*
** Problem: https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/
** Article: https://memcpy0.blog.csdn.net/article/details/130140449
** Author: memcpy0
*/
class Solution {
public:
	int longestDecomposition(string s) {
		if (s.empty()) return 0;
		for (int i = 1, n = s.length(); i <= n / 2; ++i) // 枚举前后缀长度
			if (s.substr(0, i) == s.substr(n - i)) // 立刻分割
				return 2 + longestDecomposition(s.substr(i, n - i * 2));
		return 1; // 无法分割
	}
};
/*
class Solution {
public:
	int longestDecomposition(string s) {
		int ans = 0;
		while (!s.empty()) {
			int i = 1, n = s.length();
			while (i <= n / 2 && s.substr(0, i) != s.substr(n - i)) // 枚举前后缀
				++i;
			if (i > n / 2) { // 无法分割
				++ans;
				break;
			}
			ans += 2; // 分割出s[:i]和s[n-i:]
			s = s.substr(i, n - i * 2);
		}
		return ans;
	}
};
*/