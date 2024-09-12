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
        int n, x;
        cin >> n >> x;
        x++;

        vector<int> a(n);
        int all{};
        for (int &y : a) {
            cin >> y;
            all ^= y;
        }

        if (all >= x) {
            cout << "-1\n";
            continue;
        }

        auto domerge = [&x](vector<int>& todo, int bit) {
            int mask = 1 << bit;
            vector<int> done;
            int last{};
            for (int x : todo) {
                last ^= x;
                if ((last & mask) == 0) {
                    done.push_back(last);
                    last = 0;
                }
            }

            todo = done;
        };

        int ans = 1;
        for (int b = 30; b >= 0; b--) {
            int mask = 1 << b, count{};

            for (int y : a) {
                count += ((y & mask) != 0);
            }

            if (x & mask) {
                if (count == 0) {
                    ans = max(ans, sz(a));
                    break;
                }

                // if count is odd, nothing we can do at this point
                if (count % 2 == 0) {
                    // if even, we can try merging here to force a 0
                    vector<int> cpy = a;
                    domerge(cpy, b);
                    ans = max(ans, sz(cpy));
                }
            }
            else {
                if (count % 2) {
                    break; // cant procede from this point
                }

                if (count != 0) {
                    // we need to perform some merges
                    domerge(a, b);
                }
            }
        }

        cout << ans << '\n';
    }
}

// check to see if we can make 0
