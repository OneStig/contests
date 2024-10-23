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

const int MAX_X = 1e5;
const int MAX_A = 1e6;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<vector<int>> fact(1e5 + 1);

    set<int> fc, bc;

    for (int i = 1; i <= MAX_A; i++) {
        fc.insert(i);
        bc.insert(i);
    }

    for (int i = 1; i <= MAX_X; i++) {
        for (int j = i; j <= MAX_X; j += i) {
            fact[j].push_back(i);
        }
    }

    int c, d;
    cin >> c >> d;

    for (int i = c; i <= d; i++) {
        string s;
        cin >> s;
        bool f = 0, b = 0;

        if (s == "Fizz") {
            f = 1;
        }
        else if (s == "Buzz") {
            b = 1;
        }
        else if (s == "FizzBuzz") {
            f = 1, b= 1;
        }

        if (f) {
            set<int> nw;
            for (int x : fact[i]) {
                if (fc.contains(x)) {
                    nw.insert(x);
                }
            }

            fc = nw;
        }
        else {
            for (int x : fact[i]) {
                fc.erase(x);
            }
        }

        if (b) {
            set<int> nw;
            for (int x : fact[i]) {
                if (bc.contains(x)) {
                    nw.insert(x);
                }
            }

            bc = nw;
        }
        else {
            for (int x : fact[i]) {
                bc.erase(x);
            }
        }

    }

    cout << *fc.begin() << ' ' << *bc.begin() << '\n';
}
