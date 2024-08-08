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

    int n;
    cin >> n;

    vector<vector<int> > stacks(n);

    for (auto& x : stacks) {
        int k;
        cin >> k;
        x.resize(k);
        for (int& y : x) {
            cin >> y;
            y--;
        }
    }

    vector<int> ans(n, -1);
    stack<int> curStack;

    for (int i = 0; i < n; i++) {
        int cur = i;
        while (true) {
            if (ans[cur] == -2) {
                while (true) {
                    int v = curStack.top();
                    curStack.pop();
                    ans[v] = -1;

                    stacks[v].pop_back();
                    if (v == cur) {
                        break;
                    }
                }
            }

            if (stacks[cur].empty()) {
                ans[cur] = cur;
            }

            if (ans[cur] != -1) {
                while (!curStack.empty()) {
                    int v = curStack.top();
                    curStack.pop();
                    ans[v] = ans[cur];
                }
                break;
            }

            ans[cur] = -2;
            curStack.push(cur);
            cur = stacks[cur].back();
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << ' ';
    }

    cout << '\n';
}
