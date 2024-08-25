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

int n, k;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    vector<int> t(n);
    for (int& x : t) cin >> x;

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < k; i++) {
        pq.push(t[i]);
    }
    int next = k;

    map<int, vector<int> > adj; // going backwards
    int anstime = -1;
    while (!pq.empty() && anstime == -1) {
        int cur = pq.top(), count = 0;
        while (!pq.empty() && pq.top() == cur) {
            pq.pop();
            count++;
        }
        int cap = next + count;
        while (next < cap) {
            if (next == n) {
                anstime = cur;
                break;
            }

            adj[cur + t[next]].push_back(cur);
            pq.push(cur + t[next]);
            next++;
        }
    }

    set<int> goodtimes;
    goodtimes.insert(anstime);
    queue<int> todo;
    todo.push(anstime);

    while (!todo.empty()) {
        int cur = todo.front();
        todo.pop();

        for (int& x : adj[cur]) {
            if (goodtimes.find(x) == goodtimes.end()) {
                goodtimes.insert(x);
                todo.push(x);
            }
        }
    }

    cout << anstime << '\n';
    for (int i = 0; i < k; i++) {
        if (goodtimes.find(t[i]) == goodtimes.end()) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }

    cout << '\n';
}
