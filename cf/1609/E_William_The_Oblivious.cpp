#include <bits/stdc++.h>

using namespace std;

struct SegTree
{
    int comb(int a, int b) { return a + b; }
    int n;
    vector<int> segt;
    void init(int _n)
    {
        n = _n;
        segt.assign(2 * n, 0);
    }
    void pull(int p) { segt[p] = comb(segt[2 * p], segt[2 * p + 1]); }
    void update(int p, int val)
    {
        segt[p += n] = val;
        for (p /= 2; p; p /= 2)
            pull(p);
    }
    int query(int l, int r)
    {
        int ra = 0, rb = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                ra = comb(ra, segt[l++]);
            if (r & 1)
                rb = comb(segt[--r], rb);
        }
        return comb(ra, rb);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    SegTree prea;
    SegTree preb;
    SegTree prec;

    prea.init(n);
    preb.init(n);
    prec.init(n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a') {
            prea.update(i, 1);
        }
        else if (s[i] == 'b') {
            preb.update(i, 1);
        }
        else {
            prec.update(i, 1);
        }
    }

    long long cursol = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
        {
            cursol += prea.query(0, i) * prec.query(i, n - 1);
        }
    }

    // cout << cursol << endl;

    for (int i = 0; i < q; i++)
    {
        int p;
        char c;

        cin >> p >> c;

        p--;

        long long reduction = 0;

        if (s[p] == 'a')
        {
            reduction = preb.query(p, n - 1) * prec.query(p, n - 1);
        }
        else if (s[p] == 'b')
        {
            reduction = prea.query(0, p) * prec.query(p, n - 1);
        }
        else
        {
            reduction = prea.query(0, p) * preb.query(0, p);
        }

        if (s[p] == 'a') {
            prea.update(p, 0);
        }
        else if (s[p] == 'b') {
            preb.update(p, 0);
        }
        else {
            prec.update(p, 0);
        }

        long long ans = 0;

        s[p] = c;

        if (s[p] == 'a') {
            prea.update(p, 1);
            ans += preb.query(p, n - 1) * prec.query(p, n - 1);
        }
        else if (s[p] == 'b') {
            preb.update(p, 1);
            ans += prea.query(0, p) * prec.query(p, n - 1);
        }
        else {
            prec.update(p, 1);
            ans += prea.query(0, p) * preb.query(0, p);
        }

        cursol = cursol + ans - reduction;
        cout << cursol << endl;
    }
}