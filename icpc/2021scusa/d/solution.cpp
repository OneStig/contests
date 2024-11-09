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

const ld MX_ERR = 1e-8;

ld area(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c){
    return abs(a.first * b.second - c.first * b.second + c.first * a.second - a.first * c.second + b.first * c.second - b.first * a.second);
}

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }

    ld total_area = 0;
    for(int i = 2; i < n; ++i){
        total_area += area(a[0], a[i - 1], a[i]);
    }

    ld current_area = 0;
    int j = n - 1;
    for(int i = 2; i < n; ++i){
        current_area += area(a[0], a[i - 1], a[i]);
        if(2 * current_area > total_area){
            j = i;
            break;
        }
    }

    current_area -= area(a[0], a[j - 1], a[j]);

    pair<ld, ld> left = a[j - 1], right = a[j];
    while (dist(left, right) > MX_ERR){
        pair<ld, ld> M = {(left.first + right.first) / 2.0, (left.second + right.second) / 2.0};
        // M.first = ((ld)1.0 - mid) * a[j - 1].first + (mid) * a[j].first;
        // M.second = ((ld)1.0 - mid) * a[j - 1].second + (mid) * a[j].second;
        // dbg(left, right, M, dist(left, right));

        ld new_area = current_area + area(a[0], a[j - 1], M);
        if (new_area * 2.0 == total_area) {
            left = M;
            right = M;
            break;
        }
        if(new_area * 2.0 < total_area){
            left = M;
        }
        else{
            right = M;
        }
    }


    pair<ld, ld> M = {(left.first + right.first) / 2.0, (left.second + right.second) / 2.0};
    // M.first = ((ld)1.0 - l) * a[j - 1].first + l * a[j].first;
    // M.second = ((ld)1.0 - l) * a[j - 1].second + l * a[j].second;
    // dbg(total_area, l, (1.0 - l), M);

    cout << fixed << setprecision(7) << M.first << " " << M.second << "\n";
}
