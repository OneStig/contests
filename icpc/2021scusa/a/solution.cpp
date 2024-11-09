#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }//

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define double long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define a first
#define b second

const int INF = 1e9;

vector<double> lst;
int counter = 0;

const int one = 1;
double solve(int n, int left) {
    unordered_map<int, double> cache;
    vector<double > temp(n, 0);
    vector<int> stack = { left };
    while (stack.size() != 0) {
        left = stack.back();
        // cout << left << "\n";
        stack.pop_back();
        counter += 1;
        //cout << n << " " << left << "\n";
        double ans = 0;
        double p1 = 1;
        double p2 = 1;
        int num = 0;
        bool good = true;
        for (int i = 0; i < n; i++) {
            if ((left & (one << i))) {
                p1 *= lst[i];
                p2 *= 1 - lst[i];
                num += 1;
                if (cache.find(left ^ (one << i)) == cache.end()){
                    good = false;
                    num = INF;
                    break;
                }
            }
        }

        if (num <= 2) {
            cache[left] = 0;
            continue;
        }

        if (!good) {
            stack.push_back(left);
            for (int i = 0; i < n; i++) {
                if ((left & (one << i))) {
                    if (cache.find(left ^ (one << i)) == cache.end()) {
                        stack.push_back(left ^ (one << i));
                    }
                }
            }
            continue;
        }

        double probsum = 0;
        for (int i = 0; i < n; i++) {
            if ((left & (one << i))) {
                temp[i] = (p1 / (lst[i])) * (1 - lst[i]) + (p2 / (1 - lst[i])) * (lst[i]);
                probsum += temp[i];
            }
        }
        //cout << temp << "\n";
        ans += (1 / (probsum));
        for (int i = 0; i < n; i++) {
            if (left & (one << i)) {
                //cout << i << " " << ans << "\n";
                ans += (temp[i] / probsum) * cache[(left ^ (one << i))];
            }
        }
        cache[left] = ans;
    }
    //cout << cache << "\n";
    return cache[(one << n) - 1];
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double k;
        cin >> k;
        lst.push_back(k);
    }

    cout << fixed << setprecision(10) << solve(n, (one << n) - 1) << "\n";
    //cout << counter << "\n";
    return 0;
}
