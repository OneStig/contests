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

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    int a = ask(1, n / 4);
    int b = ask(n / 4 + 1, n / 2);
    int c = ask(1, n / 2);
    int left = a != b;
    int lk = 2, rk = n - 1;

    if (a + b == 2) {
        rk = n / 4;
    }
    else if (a + b == 0) {
        lk = n / 4 + 1;
    }

    if (c == left) {
        lk = n / 2 + 1;
    }
    else {
        rk = min(rk, n / 2);
    }

    dbg(a, b, c, left, lk, rk);

    while (lk != rk) {
        int mk = (lk + rk) / 2;
        bool correct;
        if ((left && mk >= n / 2) || (!left && mk <= n / 2)) {
            int query = ask(1, mk);
            correct = query == left;
        }
        else {
            int query = ask(n - mk + 1, n);
            correct = query != left;
        }

        if (correct) {
            lk = mk + 1;
        }
        else {
            rk = mk;
        }
    }

    cout << "! " << lk << endl;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
