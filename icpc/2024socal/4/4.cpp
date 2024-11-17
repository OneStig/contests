#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define ld long double

typedef vector<int> vi;
typedef vector<ld> vld;

const int MAX_N = 2e5 + 1;

struct DSU {
    vector<ld> tom, tob, fromm, fromb;
    unordered_map<int, unordered_set<int>> intree;

    vi e; void init(int N) {
        e = vi(N, -1);
        tom = vld(N, 1);
        tob = vld(N, 0);
        fromm = vld(N, 1);
        fromb = vld(N, 0);

        for (int i = 0; i < N; i++) {
            intree[i].insert(i);
        }
    }

    ld convert(int a, int b, ld x) {
        if (a == b) {
            return x;
        }
        // from a to b, assume a b are same set
        ld toparent = tom[a] * x + tob[a];
        ld tochild = fromm[b] * toparent + fromb[b];
        return tochild;
    }

    pair<ld, ld> trans(int a, int b) {
        ld newm = tom[a] * fromm[b];
        ld newb = fromm[b] * tob[a] + fromb[b];
        return {newm, newb};
    }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int y, int x, ld m, ld b) {
        //cout << "a" << y << " " << x << " " << m << " " << b << "\n";
        int parx = get(x), pary = get(y);
        if (parx == pary) return 0;

        if (e[parx] < e[pary]) {
            // y = mx + b;
            swap(parx, pary);
            swap(x, y);
            ld revm = (ld)1.0 / m;
            ld revb = -(b / m);
            m = revm;
            b = revb;
        }

        //cout << y << " " << x << " " << m << " " << b << "\n";
        // y = mx + b;
        e[pary] += e[parx]; e[parx] = pary;
        for (int tomerge : intree[parx]) {

            intree[pary].insert(tomerge);
            pair<ld, ld> tox = trans(tomerge, x);
            //cout << tox.first << " " << tox.second << "\n";
            pair<ld,ld> top = {tom[y], tob[y]};
            //cout << top.first << " " << top.second << "\n";

            ld newm = tox.first * m;
            ld newb = m * tox.second + b;


            pair<ld,ld> t;
            t.first = newm * top.first;
            t.second = top.first * newb + top.second;
            //cout << t.first << " " << t.second << "\n";


            tom[tomerge] = t.first;
            tob[tomerge] = t.second;

            // pair<ld,ld> fromx = trans(x,tomerge);
            // pair<ld,ld> fromp = {fromm[y],fromb[y]};
            // pair<ld,ld> from;
            // from.first = fromx.first * fromp.first;
            // from.second = fromx.first * fromp.second + fromx.second;

            fromm[tomerge] = (ld)1.0 / t.first;
            fromb[tomerge] = -(t.second / t.first);
            // cout << tomerge << "\n";
            // ld newm = m * tom[tomerge];
            // ld newb = m * tob[tomerge] + b;
            //
            // tom[tomerge] = newm;
            // tob[tomerge] = newb;
            //
            // fromm[tomerge] = (ld)1.0 / newm;
            // fromb[tomerge] = -(newb / newm);
        }

        // cout << "dbg: " << y << ' ' << x << '\n';
        // cout << tom[x] << ' ' << tob[x] << ' ' << "\n";
        // cout << fromm[x] << " " << fromb[x] << "\n";

        return 1;
    }
};

unordered_map<string, int> idof;

int getid(const string& x) {
    if (idof.find(x) == idof.end()) {
        idof[x] = sz(idof);
    }

    return idof[x];
}

uci main() {
    cin.tie(0)->sync_with_stdio();

    DSU dsu;
    dsu.init(2 * MAX_N);

    string curline;

    while (getline(cin, curline)) {
        stringstream ss(curline);

        char optype;
        ss >> optype;

        if (optype == 'G') break;

        if (optype == 'K') {
            // name1 = a name2 {+/- o}
            char sign = 0;
            ld a, o = 0;
            string name1, name2;
            ss >> name1 >> name2 >> a >> name2;

            if (ss >> sign) {
                ss >> o;
                if (sign == '-') {
                    o = -o;
                }
            }

            // unify knowledge
            getid(name1);
            getid(name2);
            // cout << name1 << getid(name1) << name2 << getid(name2) << '\n';
            dsu.unite(getid(name1), getid(name2), a, o);
        }
        else if (optype == 'H') {
            // x name1 = ? name2
            ld x;
            string name1, name2;
            ss >> x >> name1 >> name2 >> name2 >> name2;

            if (!dsu.sameSet(getid(name1), getid(name2))) {
                cout << "Too hard!\n";
            }
            else {
                cout << fixed << setprecision(8) << dsu.convert(getid(name1), getid(name2), x) << '\n';
            }
        }
    }
}