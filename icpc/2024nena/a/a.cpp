#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int w, s;
    cin >> w >> s;
    int tot = s * (s + 1) / 2;
    int tw = tot * 29370 - w;
    int ans = tot - (tw / 110);
    cout << ans << '\n';
}