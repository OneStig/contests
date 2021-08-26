#include <bits/stdc++.h>

using namespace std;

int next[100010];
int prev[100010];
vector<pair<int, int>> tiles;
vector<pair<pair<int, int>, int>> boots;

int main()
{
    int n, b;
    cin >> n >> b;

    vector<int> ans(b);

    for (int i = 0; i < n; i++)
    {
        pair<int, int> tmp;

        cin >> tmp.first;
        tmp.second = i;

        tiles.push_back(tmp);
    }
    
    for (int i = 0; i < b; i++)
    {
        pair<pair<int, int>, int> tmp;
        cin >> tmp.first.first >> tmp.first.second;
        tmp.second = i;

        boots.push_back(tmp;)
    }

    sort(tiles.begin(), tiles.end());
    reverse(tiles.begin(), tiles.end());

    sort(boots.begin(), boots.end());
    reverse(boots.begin(), boots.end());


    for (int i = 0; i < n; i++)
    {
        next[i] = i + 1;
    }
    
    for (int i = n; i >= 0; i--)
    {
        prev[i] = i - 1;
    }

    int gap = 1;
    int tilep = 0;

    for (boot : boots)
    {
        while (tilep < n && tiles[tilep].first > boot.first.first)
        {
            int idx = tiles[tilep].second;
            next[prev[idx]] = next[idx];
            prev[next[idx]] = prev[idx];
            gap = max(gap, next[idx] - prev[idx]);
            tilep++;
        }

        ans[boot.second] = boot.first.second >= gap;
    }

    for (int i = 0; i < b; i++) {
        cout << ans[i] << endl;
    }    
}