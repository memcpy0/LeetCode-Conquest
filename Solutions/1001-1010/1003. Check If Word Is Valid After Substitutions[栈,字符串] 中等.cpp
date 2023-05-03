/*
** Problem: https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions
** Article: https://memcpy0.blog.csdn.net/article/details/130475947
** Author: memcpy0
*/
class Solution {
public: 
	bool isValid(string s) { // s同时作为栈
		int i = 0; // i-1表示栈顶下标,i=0表示栈为空
		for (char c : s) {
			if (c > 'a' && (i == 0 || c - s[--i] != 1))
				return false;
			if (c < 'c') s[i++] = c; // 入栈
		}
		return i == 0;
	}
};