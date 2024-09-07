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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<array<int, 2>> trie = {{-1, -1}};

        auto ins = [&trie, &k](int num, int pos) {
            int cur{};
            for (int b = k - 1; b >= 0; b--) {
                bool o = num & (1 << b);

                if (trie[cur][o] == -1) {
                    trie[cur][o] = sz(trie);
                    trie.push_back({-1, -1});
                }

                cur = trie[cur][o];
            }

            trie[cur] = {pos, num};
        };

        ins(a[0], 0);

        int best{-1}, i, j, x;

        for (int l = 1; l < n; l++) {
            int test{}, testx{}, end{};

            int cur{};
            for (int b = k - 1; b >= 0; b--) {
                test <<= 1;
                testx <<= 1;

                bool o = a[l] & (1 << b);

                if (trie[cur][o] == -1) {
                    cur = trie[cur][!o];
                }
                else {
                    test++;
                    if (!o) {
                        testx++;
                    }
                    cur = trie[cur][o];
                }
            }

            end = trie[cur][0];

            if (test > best) {
                best = test;
                i = end;
                j = l;
                x = testx;
            }

            ins(a[l], l);
        }
        dbg(best);

        cout << i + 1 << ' ' << j + 1 << ' ' << x << '\n';
    }
}
