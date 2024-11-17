#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef array<bool, 26> disp;

uci main() {
    cin.tie(0)->sync_with_stdio();

    disp mt;
    for (int i = 0; i < 26; i++) {
        mt[i] = 0;
    }

    int n, c;
    cin >> n >> c;

    unordered_map<char, disp> mp;
    for (int i = 0; i < c; i++) {
        string s;
        cin >> s;

        disp cur = mt;
        for (int j = 1; j < sz(s); j++) {
            cur[s[j] - 'a'] = 1;
        }

        mp[s[0]] = cur;
    }

    // after input, process all things
    int k, r;
    cin >> k >> r;
    vector<vector<disp>> queries(r, vector<disp>(k, mt));
    vector<disp> alive(k, mt);

    string curq;
    getline(cin, curq);
    for (int i = 0; i < r; i++) {

        getline(cin, curq);

        int seg = 0;
        for (char c : curq) {
            if (c == ',') {
                seg++;
            }
            else {
                queries[i][seg][c - 'a'] = 1;
                alive[seg][c - 'a'] = 1;
            }
        }
    }

    // query seg could be empty

    // go back through each query, find all characters that could be
    for (auto& q : queries) {
        bool smth = 0;
        for (int seg = 0; seg < k; seg++) {
            vector<char> couldbe;
            for (auto [c, bs] : mp) {
                bool good = 1;
                for (int bt = 0; bt < 26; bt++) {
                    if (alive[seg][bt] == 1 && bs[bt] != q[seg][bt]) {
                        good = 0;
                        break;
                    }
                }

                if (good) {
                    couldbe.push_back(c);
                }
            }

            sort(all(couldbe));
            if (sz(couldbe)) {
                if (smth != 0) {
                    cout << ' ';
                }
                for (char ac : couldbe) {
                    cout << ac;
                }

                smth = 1;
            }
        }

        cout << '\n';
    }
}