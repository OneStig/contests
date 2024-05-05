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

#define ll long long
#define ld long double
#define szof(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int a{}, b{};

        vector<int> as;
        int astreak{};
        bool doubleb = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                a++;
                astreak++;
            }
            else {
                as.push_back(astreak);
                astreak = 0;
                b++;

                if (i != 0 && s[i - 1] == 'B') {
                    doubleb = 1;
                }
            }
        }
        as.push_back(astreak);

        if (b == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (s[0] == 'B' || s[s.size() - 1] == 'B' || doubleb) {
            cout << a << '\n';
        }
        else {
            cout << a - *min_element(all(as)) << '\n';
            dbg(s);
        }
    }
}
