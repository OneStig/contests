#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> parents(n + 1);
        set<pair<int, int>> points;
        vector<int> indeg(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;

            for (int j = 0; j < k; j++)
            {
                int tmp;
                cin >> tmp;

                parents[tmp].push_back(i);
            }

            points.insert({k, i});
            indeg[i] = k;
        }

        bool fail = 0;
        int reads = 0;

        while (!points.empty())
        {
            auto tmp = points.begin();

            if (tmp->first != 0)
            {
                fail = 1;
                break;
            }

            while (tmp != points.end() && tmp->first == 0)
            {

                for (int i = 0; i < parents[tmp->second].size(); i++)
                {
                    int cp = parents[tmp->second][i];
                    auto tp = points.find({indeg[cp], cp});
                    points.insert({indeg[cp] - 1, cp});
                    points.erase(tp);

                    indeg[cp]--;
                }

                tmp++;

                points.erase(prev(tmp));
            }

            reads++;
        }

        if (fail)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << reads << endl;
        }
    }
}