#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
vector<int> oiio;
vector<int> poiio;

const int MAX_N = 1e6 + 1;
vector<int> ff(MAX_N);

void solve() {
    string s;
    char qtype;
    cin >> s >> qtype;

    int resp = -1;

    if (qtype == 'B') {
        int r, i;
        cin >> r >> i;

        if (i == 1 || i == r || s[3] == '1') {
            resp = 1;
        }
        else if (s == "0000") {
            resp = 0;
        }
        else if (s == "0010" || s == "1010") {
            resp = r % 2 == i % 2;
        }
        else if (s == "1100" || s == "0100") {
            resp = r % 2 != i % 2;
        }
        else if (s == "0110") {
            if (ff[r-1] > ff[i-1] + ff[r-i]) {
                resp = 0;
            }
            else {
                resp = 1;
            }
            //resp = (r % 2 == 0) && (i == 2 || i == r - 1);
        }
        else if (s == "1110") {
            resp = (r % 2 == 0);
        }
        else if (s == "1000") {
            resp = i != 2 && i != r - 1 && (r % 2 == 1);
        }
    }
    else if (qtype == 'N') {
        int r;
        cin >> r;

        if (s[3] == '1') {
            resp = r * (r + 1) / 2;
        }
        else if (s == "0000") {
            resp = r * 2 - 1;
        }
        else if (s == "0010" || s == "1010" || s == "1100" || s == "0100") {
            resp = r * 2 - 1;
            int n = (r - 2) / 2;
            resp += n * (n + 1);

            if (r % 2 == 0) {
                resp -= n;
            }
        }
        else if (s == "0110") {
            resp = poiio[r];
        }
        else if (s == "1110") {
            resp = r * 2 - 1;
            int n = (r - 2) / 2;
            resp += n * (n + 1);
        }
        else if (s == "1000") {
            resp = r * 2 - 1;
            int n = (r - 3) / 2;
            resp += n * n;
        }
    }

    cout << resp << '\n';
}


vector<int> add(vector<int> & a, vector<int> & b) {
    vector<int> c;
    for (auto i : a) {
        c.push_back(i);
    }
    for (auto i : b) {
        c.push_back(i);
    }
    return c;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc;
    cin >> tc;
    oiio = {1,2,2,4};
    vector<int> l = {2};
    while (oiio.size() < 1000000+100) {
        vector<int> l2;
        vector<int> l4;
        for (auto i : l) {
            l2.push_back(i*2);
            l4.push_back(i * 4);
        }
        oiio = add(oiio,l);
        oiio = add(oiio,l2);
        oiio = add(oiio,l2);
        oiio = add(oiio,l4);
        l = add(l,l2);
    }

    ff[1] = 0;
    for (int i = 2; i < MAX_N; i++) {
        ff[i] += ff[i - 1];
        int cur = i;
        while (cur % 2 == 0) {
            ff[i]++;
            cur /= 2;
        }
    }

    int s = 0;
    for (auto i : oiio) {
        poiio.push_back(s);
        s += i;
    }
    while (tc--) {
        solve();
    }
}