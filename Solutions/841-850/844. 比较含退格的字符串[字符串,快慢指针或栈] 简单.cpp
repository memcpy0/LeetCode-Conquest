/*
** Problem: https://leetcode.cn/problems/backspace-string-compare/
** Article: https://memcpy0.blog.csdn.net/article/details/109181989
** Author: memcpy0
*/
// BEST: 快慢指针
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '#') s[k++] = s[i];
            else if (k > 0) k--;
        }
        int d = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != '#') t[d++] = t[i];
            else if (d > 0) d--;
        }
        return s.compare(0, k, t, 0, d) == 0;
    }
};
// 双指针倒序遍历+统计退格数量+比较有效字符
class Solution {
private: //跳跃过退格和无效字符,到下一个有效字符 
    void jumpBackspace(const string &s, int &i, int &b) {
        while (i >= 0) {
            if (s[i] == '#') ++b; //计算退格
            else if (b) --b;      //不是退格但存在退格,因此不是有效字符
            else break;           //不是退格,不存在退格,是有效字符,返回
            --i;                  //是退格并计算;不是退格但存在退格---->都不是有效字符
        }
    }
public:
    bool backspaceCompare(string s, string t) { //双指针,从后往前扫描
        int sright = s.size() - 1, tright = t.size() - 1;
        int backOfS = 0, backOfT = 0;
        while (sright >= 0 || tright >= 0) {
            jumpBackspace(s, sright, backOfS);
            jumpBackspace(t, tright, backOfT);
            if (sright < 0 || tright < 0) break;          //判断是否超出范围
            if (s[sright--] != t[tright--]) return false; //有效字符比较,不相等则返回false
        }
        return sright < 0 && tright < 0;
    }
};
// 类似栈
class Solution {
private: 
    string convertToNormalText(const string &s) {
        string textStack;
        for (const char &c : s) {
            if (c != '#') textStack.push_back(c);
            else if (!textStack.empty()) textStack.pop_back();
        }
        return textStack;
    }
public:
    bool backspaceCompare(string s, string t) {
        return convertToNormalText(s) == convertToNormalText(t);
    }
};