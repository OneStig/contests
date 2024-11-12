#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define a first
#define b second
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()


uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    int n = sz(s);
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        a[i] = (s[i] - '0');
    }

    vector<set<int>> st(10);
    for(int i = 0; i < n; ++i) {
        st[a[i]].insert(i);
    }

    vector<pair<int,int>> stack = {{0,n-1}};
    int ans = 0;
    while (stack.size() != 0) {
        int x = stack.back().first;
        int y = stack.back().second;
        if (x > y) {
            stack.pop_back();
            continue;
        }

        int ind = 0;
        for(int num = 9; num >= 0; --num) {
            set<int>& curset = st[num];

            auto it1 = curset.lower_bound(x);
            if(it1 != curset.end() && *it1 <= y) {
                ind = *it1;
                break;
            }
        }

        stack.pop_back();
        ans += a[ind] * (ind - x + 1) * (y - ind + 1);
        stack.push_back({x,ind - 1});
        stack.push_back({ind+1,y});
    }

    int sum = ans;
    int total = n * (n + 1) / 2;
    if(sum >= total) {
        int full = sum / total;
        sum -= total * full;
        int g = gcd(total, sum);
        sum /= g;
        total /= g;

        if(sum == 0) {
            cout << full << "\n";
        }
        else {
            cout << full << " " << sum << "/" << total << endl;
        }
    }

    else {
        int g = gcd(total, sum);
        sum /= g;
        total /= g;

        if(sum == 0) {
            cout << "0\n";
            return 0;
        }
        cout << sum << "/" << total << endl;
    }
}