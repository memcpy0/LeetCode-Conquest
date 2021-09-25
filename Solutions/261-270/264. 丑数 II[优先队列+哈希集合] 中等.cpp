/*
** Problem: https://leetcode-cn.com/problems/ugly-number-ii/
** Article: 
** Author: memcpy0
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        unordered_set<ll> st;
        pq.push(1);
        st.insert(1);
        int ps[3] = {2, 3, 5};
        while (n-- > 0) {
            ll u = pq.top(); pq.pop();
            if (n == 0) return (int)u;
            for (int i = 0; i < 3; ++i) {
                ll v = u * ps[i];
                if (st.find(v) == st.end()) { //there isn't this ugly number
                    pq.push(v);
                    st.insert(v);
                }
            }
        }
        return 0; //never
    }
};

