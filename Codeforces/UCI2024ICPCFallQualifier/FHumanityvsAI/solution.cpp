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

bool ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    string resp;
    cin >> resp;

    return resp == "human";
}

void ans(vector<int>& h) {
    cout << "!";
    for (int& x : h) {
        cout << ' ' << x;
    }
    cout << endl;
}

mt19937 mt(time(nullptr));

void solve() {
    int n;
    cin >> n;

    int human = -1;
    while (human == -1) {
        int cand = mt() % (2 * n + 1) + 1;

        int good{}, bad{};
        for (int i = 1; i <= 2 * n + 1; i++) {
            bool x = ask(i, cand);
            if (x) {
                good++;
            }
            else {
                bad++;
            }

            if (good > n) {
                human = cand;
                break;
            }
            else if (bad > n) {
                break;
            }
        }
    }

    vector<int> ppl;
    ppl.reserve(n + 1);
    for (int i = 1; i <= 2 * n + 1; i++) {
        if (ask(human, i)) {
            ppl.push_back(i);
        }
    }

    ans(ppl);
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
