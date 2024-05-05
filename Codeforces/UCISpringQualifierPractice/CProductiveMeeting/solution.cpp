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
#define ld long double
#define szof(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        priority_queue<array<int, 2>> pq;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if (a) {
                pq.push({a, i + 1});
            }
        }

        vector<array<int, 2>> ppl;

        while (pq.size() >= 2) {
            auto f = pq.top();
            pq.pop();
            auto s = pq.top();
            pq.pop();

            ppl.push_back({f[1], s[1]});

            f[0]--;
            s[0]--;

            if (f[0]) {
                pq.push(f);
            }

            if (s[0]) {
                pq.push(s);
            }
        }

        cout << ppl.size() << '\n';

        for (auto psn : ppl) {
            cout << psn[0] << ' ' << psn[1] << '\n';
        }
    }
}
