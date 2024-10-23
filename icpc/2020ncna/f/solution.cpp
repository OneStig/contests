#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...)

// #ifndef ONLINE_JUDGE
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void lw(string& s) {
    for (char& c : s) {
        c = tolower(c);
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<pair<string, string>, array<string, 3>> iname;
    map<string, array<string, 3>> iemail, oemail;

    string s;
    while (getline(cin, s)) {
        if (s.size() < 5) break;
        array<string, 3> p = {"", "", ""};
        array<string, 3> lp = p;

        int cur = 0;
        char last = 'x';
        for (char c : s) {
            if (c == ' ' || c == '\n' || c == '\r' || c == 11 || c == 12 || c == 13 || c == '\t') {
                if (last != ' ' && last != '\t')
                    cur++;
            }
            else {
                p[cur] += c;
                lp[cur] += tolower(c);
            }

            last = c;
        }

        iname[{lp[0], lp[1]}] = p;
        iemail[lp[2]] = p;
        dbg(lp, p);
    }

    while (getline(cin, s)) {
        if (s.size() < 5) break;
        array<string, 3> p = {"", "", ""};
        array<string, 3> lp = p;

        int cur = 0;
        char last = 'x';
        for (char c : s) {
            if (c == ' ' || c == '\n' || c == '\r' || c == 11 || c == 12 || c == 13 || c == '\t') {
                if (last != ' ' && last != '\t')
                    cur++;
            }
            else {
                p[cur] += c;
                lp[cur] += tolower(c);
            }

            last = c;
        }

        bool match = 0;
        pair<string, string> fname = {lp[0], lp[1]};
        dbg(fname, lp[2]);

        if (iname.count(fname)) {
            lw(iname[fname][2]);
            iemail.erase(iname[fname][2]);
            iname.erase(fname);
            match = 1;
        }

        if (iemail.count(lp[2])) {
            lw(iemail[lp[2]][0]);
            lw(iemail[lp[2]][1]);
            iname.erase({iemail[lp[2]][0], iemail[lp[2]][1]});
            iemail.erase(lp[2]);
            match = 1;
        }

        if (!match) {
            oemail[lp[2]] = p;
        }
    }

    if (sz(iemail) + sz(oemail) == 0) {
        cout << "No mismatches.\n";
    }
    else {
        for (auto [x, y] : iemail) {
            dbg(x, y);
            cout << "I " << y[2] << ' ' << y[1] << ' ' << y[0] << '\n';
        }
        for (auto [x, y] : oemail) {
            cout << "O " << y[2] << ' ' << y[1] << ' ' << y[0] << '\n';
        }
    }
}
