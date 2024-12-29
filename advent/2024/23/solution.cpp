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

#define rep(i, a, b) for(int i = a; i < (b); ++i)

typedef bitset<520> B;
template<class F>
void cliques(vector<B>& eds, F f, B P = ~B(), B X={}, B R={}) {
	if (!P.any()) { if (!X.any()) f(R); return; }
    auto px = (P | X);
    size_t q = 0;
    for (int i = 519; i >= 0; i++) {
        if (px[i]) {
            q = i;
            break;
        }
    }
	// auto q = (P | X)._find_first();
	auto cands = P & ~eds[q];
	rep(i,0,sz(eds)) if (cands[i]) {
		R[i] = 1;
		cliques(eds, f, P & eds[i], X & eds[i], R);
		R[i] = P[i] = 0; X[i] = 1;
	}
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<string, set<string>> adj;
    string x;
    while (cin >> x) {
        string a = x.substr(0, 2);
        string b = x.substr(3, 2);
    
        adj[a].insert(b);
        adj[b].insert(a);
    }

    dbg(sz(adj));

    // int ans = 0;
    // for (auto& [a, aa] : adj) {
    //     for (auto& [b, bb] : adj) {
    //         for (auto& [c, cc] : adj) {
    //             if (aa.count(b) && aa.count(c) &&
    //                 bb.count(a) && bb.count(c) &&
    //                 cc.count(a) && cc.count(b) &&
    //                 (a[0] == 't' || b[0] == 't' || c[0] == 't')) {
    //                     ans++;
    //             }
    //         }
    //     }
    // }

    // dbg(ans / 6);

    vector<B> edges(520);
    map<string, int> tonum;
    map<int, string> tostr;

    int i = 0;
    for (auto& [x, nb] : adj) {
        tostr[i] = x;
        tonum[x] = i++;
    }

    for (auto& [x, nb] : adj) {
        for (string y : nb) {
            edges[tonum[x]][tonum[y]] = 1;
        }
    }

    set<string> ans2;
    auto output = [&](B b) {
        set<string> bruh;
        for (int i = 0; i < 520; i++) {
            if (b[i]) {
                bruh.insert(tostr[i]);
            }
        }
        if (sz(bruh) > sz(ans2)) {
            ans2 = bruh;
        }
    };

    cliques(edges, output);

    dbg(ans2);
}
