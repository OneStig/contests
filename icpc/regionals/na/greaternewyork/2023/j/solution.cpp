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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<char> dict;
    map<char, int> undict;

    for (char x = '0'; x <= '9'; x++) dict.push_back(x);
    for (char x = 'A'; x <= 'Z'; x++) dict.push_back(x);
    for (char x = 'a'; x <= 'z'; x++) dict.push_back(x);
    for (int i = 0; i < sz(dict); i++) undict[dict[i]] = i;

    int b, n;
    cin >> b >> n;

    int tg = log2(b) + 1;

    while (n--) {
        int d;
        cin >> d;
        vector<int> l(d, 0), r(d, b - 1);

        bool good = 0;
        for (int c = 0; c < tg; c++) {
            string guess = "";
            for (int i = 0; i < d; i++) {
                if (r[i] < l[i]) {
                    guess = "cheater";
                    good = 1;
                    break;
                }
                int mid = (r[i] + l[i]) / 2;
                guess += dict[mid];
            }

            cout << guess << endl;
            string resp;
            cin >> resp;

            if (resp == "correct") {
                good = 1;
                break;
            }

            for (int i = 0; i < d; i++) {
                int mid = (r[i] + l[i]) / 2;
                if (resp[i] == '=') {
                    l[i] = mid;
                }
                else if (resp[i] == '-') {
                    r[i] = mid - 1;
                }
                else {
                    l[i] = mid + 1;
                }
            }
        }

        if (!good) {
            cout << "cheater" << endl;
            string resp;
            cin >> resp;
        }
    }
}
