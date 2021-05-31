#include <bits/stdc++.h>

using namespace std;

bool inter(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4)
{
    for (int rep = 0; rep < 2; rep++)
    {
        if ((p2 - p1) * (p4 - p3) == 0)
        {
            if (p1.triangle(p2, p3) != 0)
            {
                return false;
            }
            else
            {
                for (int rep1 = 0; rep1 < 2; rep1++)
                {
                    if (max(p1.first, p2.first) < min(p3.first, p4.first))
                    {
                        return false;
                    }

                    pair<int, int> tmp = p1;
                    p1 = p3;
                    p3 = tmp;
                }
            }
            return true;
        }
        int s1 = (p2 - p1) * (p3 - p1);
        int s2 = (p2 - p1) * (p4 - p1);
        if ((s1 < 0 && s2 < 0) || (s1 > 0 && s2 > 0))
        {
            return false;
        }
        
        pair<int, int> tmp = p1;
        p1 = p3;
        p3 = tmp;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> order(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        order[i] = i;
    }
    int sol = 0;

    vector<pair<int, int>> p;
    vector<pair<pair<int, int>, pair<int, int>>> segments;

    for (int i = 0; i < 3; ++i)
    {
        segments.push_back(a[order[i]], a[order[(i + 1) % 3]]);
        p.push_back(a[order[i]]);
    }
    bool pos = true;

    for (int i = 3; i < n; i++)
    {
        vector<pair<int, int>> conn;
        for (auto &j : p)
        {
            bool curFlag = true;
            for (auto k : segments)
            {
                if (k.first == j || k.second == j)
                {
                    continue;
                }
                if (intersect(a[order[i]], j, k.first, k.second))
                {
                    curFlag = false;
                    break;
                }
            }
            if (curFlag)
            {
                conn.push_back(j);
                if (conn.size() > 3)
                {
                    break;
                }
            }
        }
        if (conn.size() != 3)
        {
            pos = false;
            break;
        }
        for (auto j : conn)
        {
            segments.push_back(j, a[order[i]]);
        }
        p.push_back(a[order[i]]);
    }
    if (pos)
    {
        ++sol;
        sol %= mod;
    }

    cout << sol << endl;
}