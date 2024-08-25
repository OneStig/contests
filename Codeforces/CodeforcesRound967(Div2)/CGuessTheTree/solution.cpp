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

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int res; cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int> > edges;
    set<int> found, notfound;
    for (int i = 2; i <= n; i++) {
        notfound.insert(i);
    }
    found.insert(1);

    while (found.size() != n) {
        int a = 1, b = *notfound.begin();
        int mid = ask(a, b);

        while (mid != a) {
            if (found.find(mid) != found.end()) {
                a = mid;
            }
            else {
                b = mid;
            }

            mid = ask(a, b);
        }

        edges.emplace_back(a, b);
        found.insert(b);
        notfound.erase(b);
    }

    cout << "!";
    for (auto& e : edges) {
        cout << ' ' << e.first << ' ' << e.second;
    }

    cout << endl;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
