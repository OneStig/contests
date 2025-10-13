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

#define double long double

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int sum = 0;
    ve<pii> pers(n);
    ve<int> many(n, 1);
    ve<bool> alive(n, 1);
    priority_queue<pair<double, int>> pid;
    map<int, int> pos;

    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;
        sum += p * w;
        pers[i] = {p, w};
        pid.push({w, i});
        pos[p] = i;
    }

    double ans = 0;
    while (sum != 0) {
        while (!alive[pid.top().second]) {
            pid.pop();
        }
        auto [ratio, best] = pid.top();
        int curpos = pers[best].first;
        pid.pop();
        
        auto cur = pos.find(curpos);
        if (sum > 0) {
            // go left
            auto prv = cur != pos.begin() ? prev(cur) : cur;
            if (cur == pos.begin() || pers[best].second * (curpos - prv->first) >= sum) {
                ans += ((double)sum / (double)pers[best].second) * (double)many[best];
                break;
            }

            // hit left thing and merge
            sum -= pers[best].second * (curpos - prv->first);
            ans += many[best] * (curpos - prv->first);
            
            // merge into best
            double totalw = pers[best].second + pers[prv->second].second;
            alive[prv->second] = 0;
            many[best] += many[prv->second];
            pos.erase(curpos);
            pos[prv->first] = best;
            double newratio = totalw / many[best];
            pers[best] = {prv->first, totalw};
            pid.push({newratio, best});
        }
        else {
            // go right
            auto nxt = next(cur);
            if (nxt == pos.end() || pers[best].second * (nxt->first - curpos) >= abs(sum)) {
                // don't hit anything
                ans += ((double)abs(sum) / (double)pers[best].second) * (double)many[best];
                break;
            }

            // hit the next thing and merge
            sum += pers[best].second * (nxt->first - curpos);
            ans += many[best] * (nxt->first - curpos);
            
            // merge into best
            double totalw = pers[best].second + pers[nxt->second].second;
            alive[nxt->second] = 0;
            many[best] += many[nxt->second];
            pos.erase(curpos);
            pos[nxt->first] = best;
            double newratio = totalw / many[best];
            pers[best] = {nxt->first, totalw};
            pid.push({newratio, best});
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';
}
