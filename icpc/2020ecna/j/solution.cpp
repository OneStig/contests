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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 9;
    vector<vector<int>> a(9, vector<int> (9));
    vector<set<int>> possible(81);

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin >> a[i][j];

            if (a[i][j]) {
                possible[i * 9 + j].insert(a[i][j]);
            }
            else {
                for (int k = 1; k <= 9; k++) {
                    possible[i * 9 + j].insert(k);
                }
            }
        }
    }


    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if (a[i][j] != 0) {
                for (int o = 0; o < 9; o++) {
                    if (o != i) {
                        possible[o * 9 + j].erase(a[i][j]);
                    }

                    if (o != j) {
                        possible[i * 9 + o].erase(a[i][j]);
                    }
                }

                // terminate for same grid
                int gi = i / 3, gj = j / 3;
                for (int bi = gi * 3; bi < (gi + 1) * 3; bi++) {
                    for (int bj = gj * 3; bj < (gj + 1) * 3; bj++) {
                        if (bi == i && bj == j) continue;
                        possible[bi * 9 + bj].erase(a[i][j]);
                    }
                }
            }
        }
    }

    auto er = [&](set<int>& aa, set<int>& bb) {
        for (int bx : bb) {
            aa.erase(bx);
        }
    };

    for(int step = 0; step < 81; ++step){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                // dbg(step, i, j);
                if(a[i][j] == 0){
                    set<int>& current = possible[i * 9 + j];
                    // dbg(current);

                    if(current.size() == 1){
                        int num = *(current.begin());
                        a[i][j] = num;
                    }
                    else {
                        // if it's the only cell that contains a required thing in row, col, cell
                        set<int> tmp = current;
                        for (int o = 0; o < 9; o++) {
                            if (o != i) {
                                er(tmp, possible[o * 9 + j]);
                                // dbg(o, j);
                            }
                        }

                        if (tmp.size() == 1) {
                            int num = *(tmp.begin());
                            a[i][j] = num;
                        }
                        else {
                            set<int> tmp = current;
                            for (int o = 0; o < 9; o++) {
                                if (o != j) {
                                    er(tmp, possible[i * 9 + o]);
                                    // dbg(i, o);
                                }
                            }

                            // dbg("hit", tmp);
                            if (tmp.size() == 1) {
                                int num = *(tmp.begin());
                                a[i][j] = num;
                            }
                            else {
                                set<int> tmp = current;
                                int gi = i / 3, gj = j / 3;
                                for (int bi = gi * 3; bi < (gi + 1) * 3; bi++) {
                                    for (int bj = gj * 3; bj < (gj + 1) * 3; bj++) {
                                        if (bi == i && bj == j) continue;
                                        // dbg(bi, bj);
                                        er(tmp, possible[bi * 9 + bj]);
                                        // if (i == 7 && j == 6) {
                                        //     dbg(bi, bj, tmp);
                                        //     dbg(possible[bi * 9 + bj]);
                                        // }
                                    }
                                }

                                if (tmp.size() == 1) {
                                    int num = *(tmp.begin());
                                    a[i][j] = num;
                                }
                            }
                        }
                    }

                    // terminate for other things:
                    if (a[i][j] != 0) {
                        for (int o = 0; o < 9; o++) {
                            if (o != i) {
                                possible[o * 9 + j].erase(a[i][j]);
                            }

                            if (o != j) {
                                possible[i * 9 + o].erase(a[i][j]);
                            }

                            if (o + 1 != a[i][j]) {
                                possible[i * 9 + j].erase(o + 1);
                            }
                        }

                        // terminate for same grid
                        int gi = i / 3, gj = j / 3;
                        for (int bi = gi * 3; bi < (gi + 1) * 3; bi++) {
                            for (int bj = gj * 3; bj < (gj + 1) * 3; bj++) {
                                if (bi == i && bj == j) continue;
                                possible[bi * 9 + bj].erase(a[i][j]);
                            }
                        }
                    }
                }
            }

            // dbg(possible[7 *9 + 6]);
        }
    }

    bool ok = true;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(a[i][j] == 0){
                ok = false;
            }
        }
    }

    if(ok){
        cout << "Easy\n";
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                cout << a[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    else{
        cout << "Not easy\n";
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(a[i][j] == 0){
                    cout << ". ";
                }

                else{
                    cout << a[i][j] << " ";
                }
            }

            cout << endl;
        }

        cout << endl;
    }
}
