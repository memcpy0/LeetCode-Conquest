/*
** Problem: https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations
** Article: https://memcpy0.blog.csdn.net/article/details/129682784
** Author: memcpy0
*/

// 枚举累加值,并计算最小轮转次数,有点难度
class Solution {
public:
	struct RotationStringPosition {
		unsigned pos, d0, d1; // 轮转后以s[pos]开头的字符串,对其奇数位加d1,偶数位加d0
	};
	static unsigned add(unsigned a, unsigned b, unsigned m) { // 即(a+b)%m,但不用取模% 
		const unsigned c = a + b;
		return c < m ? c : c - m;
	} 
	// s1<s2,reurn true
	static bool compare(string_view s, RotationStringPosition s1, RotationStringPosition s2) {
		const unsigned d1[2] = {s1.d0, s1.d1};
		const unsigned d2[2] = {s2.d0, s2.d1};
		unsigned p1 = s1.pos, p2 = s2.pos;
		const unsigned n = s.size();
		for (unsigned i = 0; i < n; ++i) { // 对比完整个字符串长度就结束
			const unsigned c1 = add(s[p1] - '0', d1[p1 % 2], 10); // 先累加,再轮转字符串s1,比较第p1位字符
			const unsigned c2 = add(s[p2] - '0', d2[p2 % 2], 10); // 先累加,再轮转字符串s2,比较第p2位字符
			if (c1 != c2) return c1 < c2;
			if (++p1 == n) p1 = 0;
			if (++p2 == n) p2 = 0;
		}
		return false;
	}  
	static unsigned minRotate(string_view s, unsigned d0, unsigned d1, unsigned gb) {
        const unsigned d[2] = {d0, d1};
        unsigned i = 0, j = gb, k = 0;
        const unsigned n = s.size(); // 两次轮转中比较第k个字符+累加值
        while (i < n && j < n && k < n) { // 开始比较
            const unsigned p1 = add(i, k, n); // 上次轮转字符串的第k个字符
            const unsigned p2 = add(j, k, n); // 本次轮转字符串的第k个字符
            const unsigned c1 = add(s[p1] - '0', d[p1 % 2], 10); // 先累加
            const unsigned c2 = add(s[p2] - '0', d[p2 % 2], 10); 
            if (c1 == c2) ++k; // 两次轮转的第k个字符+累加值后相等,继续比较下个字符
            else {
	            if (c1 < c2) { // 这次轮转后反而变大
		            j += (k / gb + 1) * gb; // 跳到后面的轮转次数
	            } else i += (k / gb + 1) * gb;
	            if (i == j) j += gb; // 错开
	            k = 0; // 两个字符不等,则下面的轮转又要从头比起
            }
        }
        return min(i, j);
	} 
    string findLexSmallestString(string s, int a, int b) {
	    const int n = s.size(), ga = gcd(a, 10), gb = gcd(b, n);
	    const unsigned na = (gb & 1) ? 10 : ga; // 累加值的限界
	    RotationStringPosition ans = {0, 0, 0};
	    for (unsigned i = 0; i < na; i += ga) { // 枚举对偶数位可能的累加值
		    for (unsigned j = 0; j < 10; j += ga) { // 枚举对奇数位可能的累加值
			    const unsigned p = minRotate(s, i, j, gb); // 求出最小轮转次数
			    if (compare(s, {p, i, j}, ans))
				    ans = {p, i, j};
		    }
	    } 
        const unsigned d[2] = {ans.d0, ans.d1}; // 下面的轮转和累加操作不能颠倒!
        for (unsigned i = 0; i < n; ++i)
            s[i] = add(s[i] - '0', d[i % 2], 10) + '0';
        const auto ptr = s.data();
        rotate(ptr, ptr + ans.pos, ptr + n);
        return s;
    }
};

/*
// 枚举+计算组内累加值使字符最小
class Solution {
public:
	struct RotationStringPosition {
		unsigned pos, d0, d1; // 轮转后以s[pos]开头的字符串,对其奇数位加d1,偶数位加d0
	};
	static unsigned add(unsigned a, unsigned b, unsigned m) { // 即(a+b)%m,但不用取模% 
		const unsigned c = a + b;
		return c < m ? c : c - m;
	} 
	// s1<s2,reurn true
	static bool compare(string_view s, RotationStringPosition s1, RotationStringPosition s2) {
		const unsigned d1[2] = {s1.d0, s1.d1};
		const unsigned d2[2] = {s2.d0, s2.d1};
		unsigned p1 = s1.pos, p2 = s2.pos;
		const unsigned n = s.size();
		for (unsigned i = 0; i < n; ++i) { // 对比完整个字符串长度就结束
			const unsigned c1 = add(s[p1] - '0', d1[i % 2], 10); // 轮转字符串s1的第p1位字符
			const unsigned c2 = add(s[p2] - '0', d2[i % 2], 10); // 轮转字符串s2的第p2位字符
			if (c1 != c2) return c1 < c2;
			if (++p1 == n) p1 = 0;
			if (++p2 == n) p2 = 0;
		}
		return false;
	}  
	string findLexSmallestString(string s, int a, int b) {
		const int n = s.size(), ga = gcd(a, 10), gb = gcd(b, n);
        RotationStringPosition ans = {0, 0, 0};
        cout << ga << endl;
		for (unsigned i = 0; i < n; i += gb) { // 最小值是x mod gcd(a,10),但这里的d0,d1是对s[i]-'0'=x的增值!
			// 在轮转后以s[pos]开头的字符串s中,直接计算使字符串最小的最小组内累加值
			const unsigned d0 = (gb & 1) ? (10 - (s[i] - '0') / ga * ga) : 0; // gb是奇数,和b是奇数效果相同; 对偶数位进行操作的最小累加值
			const unsigned d1 = 10 - (s[add(i, 1, n)] - '0') / ga * ga; // 对奇数位进行操作的最小累加值
            // x+d=x%ga,d=x%ga-x<=0,d+=10不影响结果
            // 10-x+x%ga=10-(x-x%ga)=10-(x/ga*ga)
			if (compare(s, {i, d0, d1}, ans)) ans = {i, d0, d1};	
		}
		const auto ptr = s.data();
		rotate(ptr, ptr + ans.pos, ptr + n); // 下面的轮转和累加操作不能颠倒!
		const unsigned d[2] = {ans.d0, ans.d1}; 
		for (unsigned i = 0; i < n; ++i)
			s[i] = add(s[i] - '0', d[i % 2], 10) + '0';
		return s;
	}  
};
*/

/*
// 枚举+改善累加次数
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        // 将s延长一倍,方便截取轮转后的字符串t; 而非临时对其进行截取和拼凑
        s = s + s;
        int g = gcd(b, n);
        auto findMin = [&](string &t, int start) {
            int minVal = 10, times = 0;
            for (int i = 0; i <= 9; ++i) {
                int added = ((t[start] - '0') + i * a) % 10;
                if (added < minVal) {
                    minVal = added;
                    times = i;
                }
            }
            for (int i = start; i < n; i += 2) // 组内累加次数相同
                t[i] = '0' + ((t[i] - '0') + times * a) % 10;
        };
        for (int i = 0; i < n; i += g) {
            string t = s.substr(i, n);
            findMin(t, 1);
            if (b % 2) findMin(t, 0); // b是偶数
            ans = min(ans, t);
        }
        return ans;
    }
};
*/

/* 
// 枚举+改善轮转次数
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        // 将s延长一倍,方便截取轮转后的字符串t; 而非临时对其进行截取和拼凑
        s = s + s;
        int g = gcd(b, n);
        for (int i = 0; i < n; i += g) { // 模拟轮转b位,最多不超过n次
            for (int j = 0; j <= 9; ++j) { // 模拟对字符串奇数位累加,最多不超过10次
                int kLimit = (b & 1) ? 9 : 0; // b是奇数则可以轮转后操作原本的偶数位; 否则只能操作奇数位
                for (int k = 0; k <= kLimit; ++k) {
                    // 每次进行累加前,重新截取t
                    string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2)
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    for (int p = 0; p < n; p += 2)
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    ans = min(ans, t);  
                }
            }
        }
        return ans;
    }
};
*/

/* 
// 枚举
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        vector<int> vis(n);
        string res = s;
        // 将 s 延长一倍，方便截取轮转后的字符串 t
        s = s + s;
        for (int i = 0; vis[i] == 0; i = (i + b) % n) { // <= n
            vis[i] = 1;
            for (int j = 0; j < 10; j++) { // <= 10
                int k_limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= k_limit; k++) { // <= 10
                    // 每次进行累加之前，重新截取 t
                    string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = min(res, t);
                }
            }
        }
        return res;
    }
};
*/

/* 
// BFS+哈希集合
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> rec;
        queue<string> q;
        q.push(s);
        string ans = s;
        rec.emplace(s);
        while (!q.empty()) {
            string v = q.front(); q.pop();
            if (v < ans) ans = v;
            string v1 = v.substr(v.size() - b) + v.substr(0, v.size() - b);
            if (!rec.count(v1)) {
                q.emplace(v1);
                rec.emplace(v1);
            }
            for (int i = 1; i < v.size(); i += 2) {
                int val = (v[i] - '0' + a) % 10;
                v[i] = val + '0';
            }
            if (!rec.count(v)) {
                q.push(v);
                rec.emplace(v);
            }
        }
        return ans;
    }
};
*/