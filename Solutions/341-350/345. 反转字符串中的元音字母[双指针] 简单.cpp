/*
** Problem: https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
** Article: https://memcpy0.blog.csdn.net/article/details/108963434
** Author: memcpy0
*/
class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    string reverseVowels(string s) {
        if (s.size() <= 1) return s;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(tolower(s[i]))) ++i;
            while (i < j && !isVowel(tolower(s[j]))) --j;
            if (i < j) swap(s[i++], s[j--]); 
        }
        return s;
    }
};