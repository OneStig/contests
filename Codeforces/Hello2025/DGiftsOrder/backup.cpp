#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        ve<int> a(n);
        for (int& x : a) cin >> x;

        multiset<int> ans;
        set<int> seg;
        seg.insert(0);
        
        int dir = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                seg.insert(i - 1);
                seg.insert(i);
                dir = 0;
            }
            else {
                int cdir = (a[i] - a[i - 1]) / abs(a[i] - a[i - 1]);
                if (dir == 0) {
                    dir = cdir;
                }
                else if (dir != cdir) {
                    seg.insert(i - 1);
                    dir = cdir;
                }
            }
        }

        seg.insert(n - 1);
        dbg(seg);

        auto last = seg.begin();
        for (auto it = next(seg.begin()); it != seg.end(); it++) {
            ans.insert(abs(a[*it] - a[*last]) - (*it - *last));
            last = it;
        }

        dbg(ans);

        cout << *ans.rbegin() << '\n';

        while (q--) {
            int p, x;
            cin >> p >> x;
            p--;
            if (a[p] == x) {
                cout << *ans.rbegin() << '\n';
                continue;
            }
            // do the update
            

            if (seg.count(p)) {
                auto cur = seg.find(p);
                int ul = *cur, ur = *cur;

                if (p != 0) {
                    auto pr = prev(cur);
                    ans.erase(ans.find(abs(a[*cur] - a[*pr]) - (*cur - *pr)));

                    if (a[p - 1] == a[p] || (a[p - 1] < a[p] && x <= a[p - 1]) || (a[p - 1] > a[p] && x >= a[p - 1])) {
                        seg.insert(p - 1);
                        ul = min(ul, p - 1);
                    }
                }

                if (p != n - 1) {
                    auto nxt = next(cur);
                    ans.erase(ans.find(abs(a[*nxt] - a[*cur]) - (*nxt - *cur)));
                    if (a[p + 1] == a[p] || (a[p + 1] < a[p] && x <= a[p + 1]) || (a[p + 1] > a[p] && x >= a[p + 1])) {
                        seg.insert(p + 1);
                        ur = max(ur, p + 1);
                    }
                }

                a[p] = x;

                if (p != 0 && p != n - 1) {
                    if ((a[p] > a[p - 1] && a[p + 1] > a[p]) || ((a[p] < a[p - 1]) && a[p + 1] < a[p])) {
                        seg.erase(p);
                    }
                }

                for (auto it = seg.lower_bound(ul); *it != ur; it++) {
                    int left = *it, right = *next(it);
                    ans.insert(abs(a[right] - a[left]) - (right - left));
                }
            }
            else {
                auto nxt = seg.upper_bound(p);
                auto in = prev(nxt);
                int nxtv = *nxt, inv = *in;
                ans.erase(ans.find(abs(a[*nxt] - a[*in]) - (*nxt - *in)));
                int dir = (a[*nxt] - a[*in]) / abs(a[*nxt] - a[*in]);

                a[p] = x;

                if (a[p] == a[p - 1]) {
                    seg.insert(p - 1);
                    seg.insert(p);
                    ans.insert(abs(a[p - 1] - a[inv]) - ((p - 1) - inv));
                    ans.insert(abs(a[nxtv] - a[p]) - (nxtv - p));
                }
                else if (a[p] == a[p + 1]) {
                    seg.insert(p);
                    seg.insert(p + 1);
                    ans.insert(abs(a[p] - a[inv]) - (p - inv));
                    ans.insert(abs(a[nxtv] - a[p + 1]) - (nxtv - (p + 1)));
                }
            }


            // prnt ans
            cout << *ans.rbegin() << '\n';
        }
    }
}
