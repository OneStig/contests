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

bool ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int resp;
    cin >> resp;
    return resp;
}

void ans(int x) {
    cout << "! " << x << endl;
}

bool cons(int x, int y) { // check consistency on a range
    bool cur = 0;
    for (int i = x; i < y; i++) {
        cur ^= !(ask(i, i + 1));
    }

    cur ^= !(ask(y, x));

    return !cur;
}

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n;

    while (r - l > 2) {
        int mid = (l + r - 1) / 2;
        if (cons(l, mid)) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    if (r == l) {
        ans(l);
    }
    else if (r - l == 1) {
        if (l > 1) {
            if (cons(l -1, l)) {
                ans(r);
            }
            else {
                ans(l);
            }
        }
        else {
            if (cons(r, r + 1)) {
                ans(l);
            }
            else {
                ans(r);
            }
        }
    }
    else {
        bool a = cons(l, l + 1), b = cons(l + 1, r);

        if (a) {
            ans(r);
        }
        else if (b) {
            ans(l);
        }
        else {
            ans(l + 1);
        }
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
