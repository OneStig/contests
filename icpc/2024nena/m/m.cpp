#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

map<char, char> LS = {
    {'`', '1'},
    {'~', '!'},
    {'1', '2'},
    {'!', '@'},
    {'2', '3'},
    {'@', '#'},
    {'3', '4'},
    {'#', '$'},
    {'4', '5'},
    {'$', '%'},
    {'5', '6'},
    {'%', '^'},
    {'6', '7'},
    {'^', '&'},
    {'q', 'w'},
    {'Q', 'W'},
    {'w', 'e'},
    {'W', 'E'},
    {'e', 'r'},
    {'E', 'R'},
    {'r', 't'},
    {'R', 'T'},
    {'t', 'y'},
    {'T', 'Y'},
    {'a', 's'},
    {'A', 'S'},
    {'s', 'd'},
    {'S', 'D'},
    {'d', 'f'},
    {'D', 'F'},
    {'f', 'g'},
    {'F', 'G'},
    {'g', 'h'},
    {'G', 'H'},
    {'z', 'x'},
    {'Z', 'X'},
    {'x', 'c'},
    {'X', 'C'},
    {'c', 'v'},
    {'C', 'V'},
    {'v', 'b'},
    {'V', 'B'},
    {'b', 'n'},
    {'B', 'N'}
};

map<char, char> RS = {
    {'7', '6'},
    {'&', '^'},
    {'8', '7'},
    {'*', '&'},
    {'9', '8'},
    {'(', '*'},
    {'0', '9'},
    {')', '('},
    {'-', '0'},
    {'_', ')'},
    {'=', '-'},
    {'+', '_'},
    {'y', 't'},
    {'Y', 'T'},
    {'u', 'y'},
    {'U', 'Y'},
    {'i', 'u'},
    {'I', 'U'},
    {'o', 'i'},
    {'O', 'I'},
    {'p', 'o'},
    {'P', 'O'},
    {'[', 'p'},
    {'{', 'P'},
    {']', '['},
    {'}', '{'},
    {'\\', ']'},
    {'|', '}'},
    {'h', 'g'},
    {'H', 'G'},
    {'j', 'h'},
    {'J', 'H'},
    {'k', 'j'},
    {'K', 'J'},
    {'l', 'k'},
    {'L', 'K'},
    {';', 'l'},
    {':', 'L'},
    {'\'', ';'},
    {'"', ':'},
    {'n', 'b'},
    {'N', 'B'},
    {'m', 'n'},
    {'M', 'N'},
    {',', 'm'},
    {'<', 'M'},
    {'.', ','},
    {'>', '<'},
    {'/', '.'},
    {'?', '>'}
};

const int OFFSET = 'a' - 'A';

string flip(string s) {
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += OFFSET;
        }
        else if (c >= 'a' && c <= 'z') {
            c -= OFFSET;
        }
    }

    return s;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc;
    string pwd;
    cin >> pwd >> tc;
    int n = sz(pwd);

    while (tc--) {
        string check;
        cin >> check;

        if (sz(check) == n) {
            if (pwd == check || pwd == flip(check)) {
                cout << "YES\n";
                continue;
            }

            // check LS and RS
            string lsstr = pwd;
            for (char& c : lsstr) {
                if (LS.find(c) != LS.end()) {
                    c = LS[c];
                }
            }

            if (check == lsstr || check == flip(lsstr)) {
                cout << "YES\n";
                continue;
            }

            string rsstr = pwd;
            for (char& c : rsstr) {
                if (RS.find(c) != RS.end()) {
                    c = RS[c];
                }
            }

            if (check == rsstr || check == flip(rsstr)) {
                cout << "YES\n";
                continue;
            }
        }
        else if (sz(check) + 1 == n) {
            // try removing character from pwd;
            bool yes = 0;
            for (int i = 0; i < n; i++) {
                string cur = pwd.substr(0, i) + pwd.substr(i + 1, n - i - 1);
                if (cur == check || cur == flip(check)) {
                    yes = 1;
                    break;
                }
            }

            if (yes) {
                cout << "YES\n";
                continue;
            }
        }
        else if (sz(check) - 1 == n) {
            // try removing character from check;
            bool yes = 0;
            for (int i = 0; i < sz(check); i++) {
                string cur = check.substr(0, i) + check.substr(i + 1, sz(check) - i - 1);
                if (cur == pwd || flip(cur) == pwd) {
                    yes = 1;
                    break;
                }
            }

            if (yes) {
                cout << "YES\n";
                continue;
            }
        }

        cout << "NO\n";
    }
}