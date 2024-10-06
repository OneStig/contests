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
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> left, right;
        k *= 2;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            left[x]++;
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            right[x]++;
        }

        vector<int> common, l, r;
        for (auto& [x, f] : left) {
            if (f == 1) {
                common.push_back(x);
            }
            else {
                l.push_back(x);
            }
        }

        for (auto& [x, f] : right) {
            if (f == 2) {
                r.push_back(x);
            }
        }

        vector<int> al, ar;
        while (k >= 2 && !l.empty()) {
            al.push_back(l.back());
            al.push_back(l.back());
            ar.push_back(r.back());
            ar.push_back(r.back());
            l.pop_back();
            r.pop_back();
            k -= 2;
        }

        while (k > 0) {
            al.push_back(common.back());
            ar.push_back(common.back());
            common.pop_back();
            k--;
        }

        for (auto& x : al) cout << x << ' ';
        cout << '\n';
        for (auto& x : ar) cout << x << ' ';
        cout << '\n';
    }
}
