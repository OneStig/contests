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

const int BIG = 1e5;

vector<string> table = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
    "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----."
};

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<char> dict;
    map<char, int> undict;
    map<string, char> unmorse;

    for (char x = 'A'; x <= 'Z'; x++) dict.push_back(x);
    for (char x = '0'; x <= '9'; x++) dict.push_back(x);

    for (int i = 0; i < sz(dict); i++) {
        undict[dict[i]] = i;
        unmorse[table[i]] = dict[i];
    }


    string s;
    getline(cin, s);
    string processed = "";

    for (char c : s) {
        if (undict.contains(c)) {
            processed += c;
        }
    }

    s = processed;

    string ms = "";

    for (char c : s) {
        ms += table[undict[c]];
    }

    // first check if already palindrome
    bool good = 1;
    for (int i = 0; i < sz(ms) / 2; i++) {
        if (ms[i] != ms[sz(ms) - i - 1]) {
            good = 0;
            break;
        }
    }

    if (good) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = BIG;
    string best = "";
    // not already a palindrome so lets reflect range [0, p] and run dp
    // 0111 | --------
    //    ^-p
    // reflect = 1110
    for (int p = 0; p < sz(ms); p++) {
        // first the section following p must be a palindrome
        bool good = 1;
        for (int i = 0; i < (sz(ms) - p - 1) / 2; i++) {
            if (ms[p + 1 + i] != ms[sz(ms) - i - 1]) {
                good = 0;
                break;
            }
        }

        if (!good) continue;

        // now we can run dp to find min to compose reflect([0, p])
        string reflect = ms.substr(0, p + 1);
        reverse(all(reflect));
        int len = sz(reflect);

        vector<int> dp(len + 1, BIG);
        vector<string> dps(len + 1);
        dp[0] = 0;
        dps[0] = "";

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= 5; j++) {
                if (i - j < 0) break;
                string sect = reflect.substr(i - j, j);

                if (unmorse.contains(sect)) {
                    if (dp[i - j] + 1 < dp[i]) {
                        dp[i] = dp[i - j] + 1;
                        dps[i] = dps[i - j] + unmorse[sect];
                    }
                }
            }
        }

        if (dp[len] < ans) {
            ans = dp[len];
            best = dps[len];
        }

    }

    cout << ans << ' ' << best << '\n';
}

// FOOTS -> 3 0QI -------.-..
// FOOTS -> 3 0GD -------.-..

// 0 -> -----
// Q -> --.-
// I -> ..
