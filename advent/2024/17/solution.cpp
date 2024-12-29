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

int combo(char c, int& a, int& b, int& c_val) {
    switch (c) {
        case '4': return a;
        case '5': return b;
        case '6': return c_val;
        case '7': throw runtime_error("Invalid operation.");
        default: return c - '0';
    }
}

uci main() {
    int oa, ob, oc;
    string line;

    // Read inputs for oa, ob, and oc
    getline(cin, line);
    oa = stoi(line.substr(line.find(':') + 1));

    getline(cin, line);
    ob = stoi(line.substr(line.find(':') + 1));

    getline(cin, line);
    oc = stoi(line.substr(line.find(':') + 1));

    // Skip an empty line
    getline(cin, line);

    // Read program input
    getline(cin, line);

    getline(cin, line);
    vector<int> prog = {2,4,1,1,7,5,4,6,1,4,0,3,5,5,3,0};
    // stringstream ss(line.substr(line.find(':') + 2));
    // string token;
    // while (getline(ss, token, ',')) {
    //     prog.push_back(stoi(token));
    // }

    dbg(prog);

    for (int ta = 0; ta < 10000000000LL; ++ta) {
        if (ta % 10000 == 0) {
            cout << ta << endl;
        }

        int a = ta;
        int b = ob;
        int c = oc;
        vector<int> output;
        int ip = 0;

        while (ip < prog.size()) {
            int op = prog[ip];
            switch (op) {
                case 0: 
                    a = a >> combo(prog[ip + 1], a, b, c);
                    break;
                case 1: 
                    b = b ^ prog[ip + 1];
                    break;
                case 2: 
                    b = combo(prog[ip + 1], a, b, c) % 8;
                    break;
                case 3: 
                    if (a != 0) {
                        ip = prog[ip + 1] - 2;
                    }
                    break;
                case 4: 
                    b = b ^ c;
                    break;
                case 5: 
                    output.push_back(combo(prog[ip + 1], a, b, c) % 8);
                    if (output.size() > prog.size() || output.back() != prog[output.size() - 1]) {
                        ip = prog.size();
                    }
                    break;
                case '6': 
                    b = a >> combo(prog[ip + 1], a, b, c);
                    break;
                case '7': 
                    c = a / static_cast<int>(pow(2, combo(prog[ip + 1], a, b, c)));
                    break;
                default:
                    throw runtime_error("Invalid operation.");
            }
            ip += 2;
        }

        if (output == prog) {
            cout << "ans2: " << ta << endl;
            break;
        }
    }

    cout << "concluded" << endl;
    return 0;
}
