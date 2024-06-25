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

void solve() {
    int n, q;
    cin >> n >> q;

    q--;
    int d;
    cin >> d;

    vector<int> main, branch;
    main.push_back(1);
    branch.push_back(2);

    for (int i = 1; i <= d; i++) {
        cout << i << ' ' << i + 1 << '\n';
        main.push_back(i + 1);
    }

    for (int i = d + 2; i <= n; i++) {
        cout << branch.back() << ' ' << i << '\n';
        branch.push_back(i);
    }

    cout << "-1 -1 -1\n";

    int lastd = d;
    while (q--) {
        cin >> d;
        if (d == lastd) {
            cout << "-1 -1 -1\n";
        }
        else if (d < lastd) {
            int diff = lastd - d;
            cout << main[sz(main) - diff] << ' ' << main[sz(main) - diff - 1] << ' ' << branch.back() << '\n';
            branch.insert(branch.end(), main.end() - diff, main.end());
            main.erase(main.end() - diff, main.end());
        }
        else {
            int diff = d - lastd;
            cout << branch[sz(branch) - diff] << ' ' << branch[sz(branch) - diff - 1] << ' ' << main.back() << '\n';
            main.insert(main.end(), branch.end() - diff, branch.end());
            branch.erase(branch.end() - diff, branch.end());
        }

        lastd = d;
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
