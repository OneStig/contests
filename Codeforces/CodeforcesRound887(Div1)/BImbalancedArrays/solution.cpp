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
        int n;
        cin >> n;

        vector<int> a(n);
        priority_queue<int> big;
        for (int& x : a) {
            cin >> x;
            big.push(x);
        }

        bool possib = 1;
        map<int, vector<int>> perm;
        int pos{}, neg{};
        for (int i = n; i >= 1; i--) {
            int testpos = pos + i;
            if (big.top() > testpos) {
                possib = 0;
                break;
            }

            if (big.top() == testpos) {
                big.pop();
                perm[testpos].push_back(i);
                pos++;
            }
            else {
                perm[pos].push_back(-i);
                neg++;
            }
        }

        if (possib) {
            vector<int> ans(n);
            for (int i = 0; i < n; i++) {
                if (perm[a[i]].empty()) {
                    possib = 0;
                    break;
                }

                ans[i] = perm[a[i]].back();
                perm[a[i]].pop_back();
            }

            if (possib) {
                cout << "YES\n";
                for (int& x : ans) {
                    cout << x << ' ';
                }
                cout << '\n';
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }
}

// "permutation" of n, where each could be pos or negative

// if the largest a == n, then n is positive instead of negative
// otherwise, it must be negative
