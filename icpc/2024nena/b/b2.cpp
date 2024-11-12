#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

struct RMQ {
    vector<vector<int>> jmp;
    vector<vector<int>> pos;
    RMQ(const vector<int>& V) : jmp(1, V) {
        for(int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jpm.emplace_back(sz(V) - pw * 2 + 1);
            for(int j = 0; j < sz(jmp[k]); ++j) {
                jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
    }

    int query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

int dfs(int l, int r) {

}
uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;
    int n = sz(s);
    vector<int> a(n + 2);
    a[n + 1] = 10;
    a[0] = 10;
    for(int i = 1; i <= n; ++i) {
        a[i] = (s[i - 1] - '0');
    }

    deque<int> st;
    vector<int> left_max(n), right_max(n);
    for(int i = 0; i <= n + 1; ++i) {
        while(!st.empty() && a[st.back()] <= a[i]) {
            left_max[st.back()] = i;
            st.pop_back();
        }

        st.push_back(i);
    }

    st.pop_back();

    for(int i = n + 1; i >= 0; --i) {
        while(!st.empty() && a[st.back()] <= a[i]) {
            right_max[st.back()] = i;
            st.pop_back();
        }

        st.push_back(i);
    }

    st.pop_back();

    int sum = 0;
    int total = n * (n + 1) / 2;
    for(int i = 1; i <= n; ++i) {
        sum += (i - left_max[i]) * (right_max[i] - i) * a[i];
    }

    cerr << sum << "\n";
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