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

const int MAX_A = 4e5;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<set<int>> pfacts(MAX_A + 1);
    vector<bool> isp(MAX_A + 1, 1);
    vector<int> primes;
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= MAX_A; i++) {
        if (isp[i]) {
            primes.push_back(i);
            pfacts[i].insert(i);
            for (int j = 2 * i; j <= MAX_A; j += i) {
                isp[j] = 0;
                pfacts[j].insert(i);
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        int mn = 2;

        for (int& x : a) {
            cin >> x;

            if (isp[x]) {
                mn = max(mn, x);
            }
        }

        bool good = 1;

        if (mn != 2) {
            for (int& x : a) {
                if (x < mn) {
                    good = 0;
                    break;
                }

                if (pfacts[x].count(mn)) {
                    continue;
                }

                int smprime = *pfacts[x].begin();
                if (x - smprime < 2 * mn) {
                    good = 0;
                    break;
                }
            }
        }

        cout << (good ? mn : -1) << '\n';
    }
}
