/*
** Problem: https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/
** Article: https://memcpy0.blog.csdn.net/article/details/130140449
** Author: memcpy0
*/
class Solution { 
	int base = 131;
	public int longestDecomposition(String s) {
		int n = s.length(), halfLen = n / 2;
		int h1 = 0, h2 = 0, temp = 1;
		int ans = 0;
		int maxi = 0;
		for (int i = 1; i <= halfLen ; ++i) {
			h1 = h1 * base + s.charAt(i - 1);
			h2 = h2 + s.charA(n - i) * temp;
			temp = temp * base;
			if (h1 == h2) {
				ans += 2;
				temp = 1;
				h1 = 0;
				h2 = 0;
				maxi = i;
			}
		}
		if (maxi == halfLen) ans = halfLen * 2 < halfLen ? ans + 1 : ans; // 到达的最大长度
		else ++ans; // 无法分割到中间,ans++
		return ans;
	}
}