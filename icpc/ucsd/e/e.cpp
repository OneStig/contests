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

#define pii pair<int, int>
#define a first
#define b second

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int p, n;
    cin >> p >> n;

    vector<pii> lane(2 * p, {-1, -1});
    vector<pii> done(2 * p);
    vector<queue<int>> qs(2 * p);

    set<int> events;

    // arrive, durat, is right, id
    map<int, int> arrive;
    vector<array<int, 3>> cars(n);
    for (int i = 0; i < n; i++) {
        char side;
        cin >> cars[i][0] >> cars[i][1] >> side;
        cars[i][2] = (side == 'R');

        arrive[cars[i][0]] = i;
        events.insert(cars[i][0]);
    }

    vector<int> ans(n);
    
    while (sz(events)) {
        int t = *events.begin();

        // dbg(t);
        events.erase(t);
        // process done

        for (int l = 0; l < 2 * p; l++) {
            if (done[l].a == t) {
                ans[lane[l].a] = t;
                lane[l].a = -1;
            }

            if (done[l].b == t) {
                ans[lane[l].b] = t;
                lane[l].b = -1;
            }
        }

        // move queue

        for (int l = 0; l < 2 * p; l++) {
            if (lane[l].a == -1) {
                if (lane[l].b == -1 && sz(qs[l])) {
                    int good = qs[l].front();
                    qs[l].pop();

                    lane[l].b = good;
                    done[l].b = t + cars[good][1];
                    events.insert(t + cars[good][1]);
                }

                if (lane[l].a == -1 && sz(qs[l])) {
                    int good = qs[l].front();
                    qs[l].pop();

                    lane[l].a = good;
                    done[l].a = t + cars[good][1];
                    events.insert(t + cars[good][1]);
                }
            }
        }

        // insert new
        if (arrive.find(t) != arrive.end()) {
            int newcar = arrive[t];

            bool found = 0;
            for (int i = cars[newcar][2]; i < 2 * p; i += 2) {
                if (lane[i].a == -1) {
                    found = 1;

                    if (lane[i].b == -1) {
                        lane[i].b = newcar;
                        done[i].b = t + cars[newcar][1];
                    }
                    else {
                        lane[i].a = newcar;
                        done[i].a = t + cars[newcar][1];
                    }

                    // dbg(t + cars[newcar][1]);
                    events.insert(t + cars[newcar][1]);

                    break;
                }
            }

            // dbg(newcar, found);

            if (!found) {
                int choose = cars[newcar][2];
                int best = 10000;

                for (int i = cars[newcar][2]; i < 2 * p; i += 2) {
                    if (sz(qs[i]) < best) {
                        best = sz(qs[i]);
                        choose = i;
                    }
                }

                qs[choose].push(newcar);
                dbg(choose);
            }
        }
    }

    // print ans
    for (int& x : ans) {
        cout << x << '\n';
    }
}
