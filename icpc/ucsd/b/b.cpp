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

const int MOD = 1e9 + 7;

int iv = 1;
int f(int a, int b) { return (a * b) % MOD; }

struct ST {
    vector<int> s; int n;
    ST(int n = 0) : s(2 * n, iv), n(n) {}
    void update(int i, int v) {
        for (s[i += n] = v; i /= 2;)
            s[i] = f(s[i * 2], s[i * 2 + 1]);
    }
    int query(int b, int e) {
        int r = iv;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) r = f(r, s[b++]);
            if (e % 2) r = f(s[--e], r);
        }
        return r;
    }
};

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    ST st(n);

    array<map<int, int>, 2> terms;
    array<int, 2> ans = {0, 0};
    bool cur = 1;

    terms[0][0] = 0;
    terms[1][0] = 0;

    string s;
    cin >> s;

    for (int i = 0; i < sz(s); i++) {
        if (i % 2 == 1) {
            bool mul = s[i] == '*';
            terms[mul].rbegin()->second++;
            terms[!mul][i / 2 + 1] = i / 2 + 1;
        }
        else {
            nums[i / 2] = s[i] - '0';
            st.update(i / 2, nums[i / 2]);
        }
    }

    for (int x : {0, 1}) {
        for (auto [start, end] : terms[x]) {
            ans[x] += st.query(start, end + 1);
            ans[x] %= MOD;
        }
    }

    cout << ans[1] << '\n';

    while (m--) {
        char query;
        cin >> query;

        if (query == 's') { // swap
            int a, b;
            cin >> a >> b;
            a--, b--;

            for (int x : {0, 1}) {
                auto aIt = prev(terms[x].upper_bound(a));
                auto bIt = prev(terms[x].upper_bound(b));
                ans[x] += 3 * MOD - st.query(aIt->first, aIt->second + 1) - st.query(bIt->first, bIt->second + 1);
                ans[x] %= MOD;
            }

            swap(nums[a], nums[b]);
            st.update(a, nums[a]);
            st.update(b, nums[b]);

            for (int x : {0, 1}) {
                auto aIt = prev(terms[x].upper_bound(a));
                auto bIt = prev(terms[x].upper_bound(b));
                ans[x] += st.query(aIt->first, aIt->second + 1) + st.query(bIt->first, bIt->second + 1);
                ans[x] %= MOD;
            }
        }
        else if (query == 'f') { // flip
            int a;
            cin >> a;

            for (int x : {0, 1}) {
                auto aIt = terms[x].find(a);
                if (aIt == terms[x].end()) { // pos a follows a *
                    aIt = prev(terms[x].upper_bound(a));
                    ans[x] += 3 * MOD - st.query(aIt->first, aIt->second + 1);
                    terms[x][a] = aIt->second;
                    aIt->second = a - 1;
                    ans[x] += st.query(aIt->first, a) + st.query(a, terms[x][a] + 1);
                }
                else {
                    auto prevIt = prev(aIt);
                    ans[x] += 3 * MOD - st.query(prevIt->first, prevIt->second + 1) - st.query(aIt->first, aIt->second + 1);
                    prevIt->second = aIt->second;
                    ans[x] += st.query(prevIt->first, prevIt->second + 1);
                    terms[x].erase(aIt);
                }

                ans[x] %= MOD;
            }
        }
        else { // all flip
            cur = !cur;
        }

        cout << ans[cur] << '\n';
    }
}
