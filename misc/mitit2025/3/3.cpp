#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }


typedef int uci;
typedef long double ld;

const int zero = 0;
const int one = 1;
const int inf = 1e18;

pair<int, int> iv = {INT_MIN, -1};
#define int long long
pair<int, int> f(pair<int, int> a, pair<int, int> b) { return max(a, b); } // commutative

struct ST {
  vector<pair<int, int>> s; int n;
  ST(int n = 0) : s(2*n, iv), n(n) {}
  void update(int i, pair<int, int> v) { // a[i] = v
    for (s[i += n] = v; i /= 2;)
      s[i] = f(s[i * 2], s[i * 2 + 1]);
  }
  pair<int, int> query(int b, int e) { // query [b, e)
    pair<int, int> r = iv;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) r = f(r, s[b++]);
      if (e % 2) r = f(s[--e], r);
    }
    return r;
  }
};

int n;

vector<int> lis(vector<int> const& a) {
    ST st(n + 1);
    vector<pair<int, int>> dp(a.size());

    st.update(0, {0, -1});

    for (int i = 0; i < a.size(); i++) {
        pair<int, int> best = st.query(0, a[i]);

        dp[i] = {best.first + 1, best.second};
        st.update(a[i], {dp[i].first, i});
    }

    vector<int> resp;

    int cur = 0;
    for (int i = 0; i < a.size(); i++) {
        if (dp[i].first > dp[cur].first) {
            cur = i;
        }
    }

    while (cur != -1) {
        resp.push_back(a[cur]);
        cur = dp[cur].second;
    }

    reverse(resp.begin(), resp.end());
    return resp;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = -a[i];
        }
        vector<int> inds(n,1);
        for (int i = 0; i < n; i++) {
            inds[-a[i] - 1] = i + 1;
        }
        set<int> added;
        vector<int> b = a;
        int rr = 0;
        for (int i = 0; i < (k+1)/2; i++){
            //cout << b << "\n";
            if (b.size() == 0) {
                break;
            }
            vector<int> subseq = lis(b);
            if (subseq.size() == 1) {
                break;
            }
            //cout << subseq << " " << b << "\n";
            vector<int> c;
            set<int> r;
            for (int j = 0; j < subseq.size(); j++) {
                added.insert(subseq[j]);
            }
            for (int j = 0; j < b.size(); j++) {
                if (added.find(b[j]) == added.end()) {
                    c.push_back(b[j]);
                }
            }
            rr += 1;
            b = c;
        }
        
        for (int i = 0; i < min((int)b.size(), (k + 1) / 2 - rr); i++) {
            added.insert(b[i]);

        } 
        
        if (added.size() < k) {
            cout << "NO\n";
        }
        else {
            vector<int> s;
            cout << "YES\n";
            for (auto i : added) {
                if (s.size() == k) {
                    break;
                }
                s.push_back(inds[-i-1]);
            }
            sort(s.begin(), s.end());
            for (int i = 0; i < k; i++) {
                cout << s[i] << " ";
            }
            cout << "\n";

        }
    }

}
