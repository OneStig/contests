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

int getd(int a, int b) {
    if (a == 0) return 0;
    if (b == 0) return 1;

    if (a >= b) {
        int subs = a / b;
        int moves = 1 + subs + subs / 2;
        int last = a - subs * b;
        // 1 1 0
        // 5 2 3 1 2 1 1

        if (subs % 2 == 1) {
            return moves + getd(last, abs(last - b));
        }
        else {
            return moves + getd(b, abs(last - b));
        }
    }
    else {
        // a < b
        return 1 + getd(b, abs(a - b));
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        array<int, 3> cycles = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            if (a[i] == 0 && b[i] == 0) {
                cycles[0]++;
                cycles[1]++;
                cycles[2]++;
            }
            else {
                int dist = getd(a[i], b[i]);
                cycles[dist % 3]++;
            }
        }

        if (cycles[0] == n || cycles[1] == n || cycles[2] == n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

// 5 1 4 3 1 2 1 1 0 1 1 0
//   0 1 2 3 4 5 6 7 : 1
// 1 5 4 1 3 2 1 1 0 1 1 0
//   0 1 2 3 4 5 6 7 : 1
// 4 2 2 0 2 2 0
//   0 1 2 : 2
// 6 2 4 2 2 0 2 2 0
//   0 1 2 3 4 : 1
//
// 10 2 8 6 2 4 2 2 0
//    ^     ^     ^

// 10 1 9 8 1 7 6 1 5 4 1 3 2 1 1 0
//    ^     ^     ^     ^     ^

// 11 1 10 9 1 8 7 1 6 5 1 4 3 1 2 1 1 0
//    ^      ^     ^     ^     ^     ^

// 5 2 3 1 2 1 1 0
//   ^     ^

// 11 4 7 3 4 1 3 2 1 1
