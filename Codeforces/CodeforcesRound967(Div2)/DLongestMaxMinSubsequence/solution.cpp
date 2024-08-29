#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define pii pair<int, int>
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        map<int, vector<int>> pos;
        set<int> every;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
            every.insert(a[i]);
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (const auto [x, p] : pos) {
            pq.push({p.back(), x});
        }
        pq.push({n, -1});

        int bck = 0, nxt = 0, take = -1;
        set<int> used;
        set<pii> able1, able2;
        vector<int> ans;

        while (sz(ans) < sz(every)) {
            // dbg(ans);
            while (used.contains(pq.top().second)) {
                pq.pop();
            }

            while (nxt <= pq.top().first) {
                able1.insert({a[nxt], nxt});
                able2.insert({a[nxt], -nxt});
                nxt++;
            }

            int select, selectpos;
            if (sz(ans) % 2) {
                while (able1.begin()->second < bck || used.contains(able1.begin()->first)) {
                    able1.erase(able1.begin());
                }
                select = able1.begin()->first;
                selectpos = able1.begin()->second;
            }
            else {
                while (-able2.rbegin()->second < bck || used.contains(able2.rbegin()->first)) {
                    able2.erase(prev(able2.end()));
                }
                select = able2.rbegin()->first;
                selectpos = -able2.rbegin()->second;
            }

            ans.push_back(select);
            used.insert(select);
            bck = selectpos + 1;
        }

        cout << sz(ans) << '\n';
        for (int& x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }
}
