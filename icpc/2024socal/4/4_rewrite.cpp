#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define ld long double

#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_N = 2e5 + 1;

struct LF
{
    ld m, b;
    LF(ld m, ld b) : m{m}, b{b} {}

    LF reverse() { return LF(1.0 / m, -(b / m)); }
    LF to(LF nxt) { return LF(m * nxt.m, nxt.m * b + nxt.b); }
};

struct DSU
{
    vector<LF> func;
    vi e;
    void init(int N)
    {
        e = vi(N, -1);
        func = vector<LF>(N, {1.0, 0});
    }

    int get(int x)
    {
        if (e[x] < 0)
        {
            return x;
        }

        e[x] = get(e[x]);
        func[x] = func[x].to(func[e[x]]);

        return e[x];
    }
    bool sameSet(int a, int b) { return get(a) == get(b); }

    int size(int x)
    {
        return -e[get(x)];
    }

    ld convert(int u, int v, ld x)
    {
        LF cf = func[u].to(func[v].reverse());
        return x * cf.m + cf.b;
    }

    bool unite(int y, int x, LF f)
    {
        int px = get(x), py = get(y);
        if (px == py)
            return 0;

        if (e[px] < e[py])
        {
            swap(px, py);
            swap(x, y);
            f = f.reverse();
        }

        e[py] += e[px], e[px] = py;
        func[px] = func[x].reverse().to(f).to(func[y]);

        return 1;
    }
};

unordered_map<string, int> idof;

int getid(const string &x)
{
    if (idof.find(x) == idof.end())
    {
        idof[x] = sz(idof);
    }

    return idof[x];
}

uci main()
{
    cin.tie(0)->sync_with_stdio();

    DSU dsu;
    dsu.init(2 * MAX_N);

    string curline;

    while (getline(cin, curline))
    {
        stringstream ss(curline);

        char optype;
        ss >> optype;

        if (optype == 'G')
            break;

        if (optype == 'K')
        {
            // name1 = a name2 {+/- o}
            char sign = 0;
            ld a, o = 0;
            string name1, name2;
            ss >> name1 >> name2 >> a >> name2;

            if (ss >> sign)
            {
                ss >> o;
                if (sign == '-')
                {
                    o = -o;
                }
            }

            // unify knowledge
            dsu.unite(getid(name1), getid(name2), LF(a, o));
        }
        else if (optype == 'H')
        {
            // x name1 = ? name2
            ld x;
            string name1, name2;
            ss >> x >> name1 >> name2 >> name2 >> name2;

            if (!dsu.sameSet(getid(name1), getid(name2)))
            {
                cout << "Too hard!\n";
            }
            else
            {
                cout << fixed << setprecision(8) << dsu.convert(getid(name1), getid(name2), x) << '\n';
            }
        }
    }
}
