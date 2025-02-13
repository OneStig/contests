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

#define ll long long
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int n, m;

int ask(int x, int y) {
    int answer;
    cout << "? " << x << ' ' << y << endl;
    cin >> answer;
    return answer;
}

void answer(int x, int y) {
    cout << "! " << x << ' ' << y << endl;
}

void solve() {
    cin >> n >> m;

    int d1 = ask(1, 1);

    if (d1 == 0) {
        answer(1, 1);
        return;
    }

    int d2 = ask(n, m);

    if (d2 == 0) {
        answer(n, m);
        return;
    }

    d2 = n + m - 2 - d2;

    int x2 = min(n, 1 + d1);
    int y2 = 1 + max(0, d1 - n + 1);

    d2 = ask(x2, y2);

    if (d2 == 0) {
        answer(x2, y2);
        return;
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
