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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> fixed;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];

        if (a[i] != -1) {
            fixed.push_back(i);
        }
    }

    if (sz(fixed) == 0) {
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                cout << "1 ";
            }
            else {
                cout << "2 ";
            }
        }

        cout << '\n';

        return;
    }

    bool possib = 1;

    for (int i = 0; i < sz(fixed) - 1; i++) {
        int l = a[fixed[i]], r = a[fixed[i + 1]];
        int gap = fixed[i + 1] - fixed[i];

        int ls{}, rs{};
        int lt = l, rt = r;
        while (lt != rt) {
            if (lt > rt) {
                ls++;
                lt /= 2;
            }
            else {
                rs++;
                rt /= 2;
            }
        }

        int steps = ls + rs;

        if (gap < steps || (gap - steps) % 2) {
            possib = 0;
            break;
        }

        for (int j = fixed[i] + 1; j <= fixed[i] + ls; j++) {
            b[j] = b[j - 1] / 2;
        }

        for (int j = fixed[i + 1] - 1; j >= fixed[i + 1] - rs; j--) {
           b[j] = b[j + 1] / 2;
        }

        for (int j = fixed[i] + ls + 1; j < fixed[i + 1] - rs; j++) {
            if (b[j - 1] == lt) {
                b[j] = lt * 2;
            }
            else {
                b[j] = lt;
            }
        }

    }

    if (!possib) {
        cout << -1 << '\n';
        return;
    }

    for (int i = fixed.front() - 1; i >= 0; i--) {
        if (b[i + 1] == 1) {
            b[i] = 2;
        }
        else {
            b[i] = b[i + 1] / 2;
        }
    }

    for (int i = fixed.back() + 1; i < n; i++) {
        if (b[i - 1] == 1) {
            b[i] = 2;
        }
        else {
            b[i] = b[i - 1] / 2;
        }
    }

    for (int& x : b) {
        cout << x << ' ';
    }

    cout << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
