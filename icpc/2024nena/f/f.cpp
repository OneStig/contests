#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string type, code;
    cin >> type >> code;
    string dumb;
    getline(cin, dumb);

    string s;
    getline(cin, s);

    if(type == "E") {
        int n = sz(s);
        string t;
        for(int i = 0; i < n; ++i) {
            if(isalpha(s[i])) {
                t += tolower(s[i]);
            }
        }

        //step 1
        vector<int> convert;
        for(int i = 0; i < sz(code); ++i) {
            convert.push_back(code[i] - 'a' + 2);
        }

        // step 3 and 4
        vector<char> answer(sz(t), '_');
        int pos = 0;
        for(int i = 0; i < sz(convert); ++i) {
            if(i % 2 == 0) {
                int count = 0;
                for(int j = 0; j < sz(t); ++j) {
                    if(answer[j] == '_') {
                        count++;
                    }

                    if(count % convert[i] == 0 && count != 0) {
                        count = 0;
                        answer[j] = t[pos];
                        pos++;
                    }
                }
            }

            else {
                int count = 0;
                for(int j = sz(t) - 1; j >= 0; --j) {
                    if(answer[j] == '_') {
                        count++;
                    }

                    if(count % convert[i] == 0 && count != 0) {
                        count = 0;
                        answer[j] = t[pos];
                        pos++;
                    }
                }
            }
        }
        if(sz(convert) % 2 == 0) {
            for(int j = 0; j < sz(t); ++j) {
                if(answer[j] == '_') {
                    answer[j] = t[pos];
                    pos++;
                }
            }
        }

        else {
            for(int j = sz(t); j >= 0; --j) {
                if(answer[j] == '_') {
                    answer[j] = t[pos];
                    pos++;
                }
            }
        }

        for(auto x : answer) {
            cout << x;
        }

        cout << endl;
    }

    if(type == "D") {
        string t = s;
        vector<int> convert;
        for(int i = 0; i < sz(code); ++i) {
            convert.push_back(code[i] - 'a' + 2);
        }


        string answer = "";
        for(int i = 0; i < sz(convert); ++i) {
            if(i % 2 == 0) {
                int count = 0;
                for(int j = 0; j < sz(t); ++j) {
                    if(t[j] != '_') {
                        count++;
                    }

                    if(count % convert[i] == 0 && count != 0) {
                        count = 0;
                        answer += t[j];
                        t[j] = '_';
                    }
                }
            }

            else {
                int count = 0;
                for(int j = sz(t) - 1; j >= 0; --j) {
                    if(t[j] != '_') {
                        count++;
                    }

                    if(count % convert[i] == 0 && count != 0) {
                        count = 0;
                        answer += t[j];
                        t[j] = '_';
                    }
                }
            }
        }

        if(sz(convert) % 2 == 0) {
            for(int j = 0; j < sz(t); ++j) {
                if(t[j] != '_') {
                    answer += t[j];
                    t[j] = '_';
                }
            }
        }

        else {
            for(int j = sz(t); j >= 0; --j) {
                if(t[j] != '_') {
                    answer += t[j];
                    t[j] = '_';
                }
            }
        }

        string bruh = "";
        for (char c : answer) {
            if (isalpha(c)) {
                bruh += c;
            }
        }
        cout << bruh << "\n";

    }
}