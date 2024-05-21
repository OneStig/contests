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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), a(n), b(n);
        vector<pair<int, int>> aind, aopp, bind, bopp;

        for (int i = 0; i < n; i++) {
            cin >> p[i];

            if (i % 2) {
                if (i != n - 1) {
                    aind.push_back({p[i], i});
                }

                bopp.push_back({p[i], i});
            }
            else {
                if (i != 0) {
                    bind.push_back({p[i], i});
                }

                aopp.push_back({p[i], i});
            }
        }

        // can we always achieve n / 2 - 1

        sort(all(aind));
        sort(all(bind));
        sort(all(aopp));
        sort(all(bopp));
        reverse(all(aind));
        reverse(all(bind));
        
        for (int i = n; i > n / 2 + 1; i--) {
            a[aind.back().second] = i;
            b[bind.back().second] = i;
            aind.pop_back();
            bind.pop_back();
        }

        for (int i = 1; i <= n / 2; i++) {
            a[aopp.back().second] = i;
            b[bopp.back().second] = i;
            aopp.pop_back();
            bopp.pop_back();
        }

        a[n - 1] = n / 2 + 1;
        b[0] = n / 2 + 1;

        int ascore{}, bscore{};

        for (int i = 0; i < n; i++) {
            a[i] += p[i];
            b[i] += p[i];
        }

        for (int i = 1; i < n - 1; i++) {
            ascore += (a[i] > a[i - 1] && a[i] > a[i + 1]);
            bscore += (b[i] > b[i - 1] && b[i] > b[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            a[i] -= p[i];
            b[i] -= p[i];
        }

        if (ascore > bscore) {
            for (int& x : a) {
                cout << x << ' ';
            }
        }
        else {
            for (int& x : b) {
                cout << x << ' ';
            }
        }

        cout << '\n';
        dbg(max(ascore, bscore));
    }
}
