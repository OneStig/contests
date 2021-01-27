#include <bits/stdc++.h>

using namespace std;

int N, M, T[100005], C[100005];
bool ok[100005];
vector<int> adj[100005];
array<int, 2> dat[100005];
vector<int> todo[100005];
pair<int, int> range[100005];

int co = 0;
void dfs(int x, int y)
{
    range[x].first = co++;
    for (auto& t : adj[x]) {
        if (t != y) {
            dfs(t, x);
        }
    } 
    range[x].second = co - 1;
}

vector<pair<int, int>> stor[100005];
vector<int> ord;

void dfs2(int x, int y)
{
    stor[T[x]].push_back({x, ord.size()});
    ord.push_back(x);
    for (auto& t : todo[x]) {
        if (stor[C[t]].size())
    {
        pair<int, int> y = stor[C[t]].back();
        if (y.first == x)
            ok[t] = 1;
        else
        {
            int Y = ord[y.second + 1];
            if (!anc(Y, dat[t][0] + dat[t][1] - x))
                ok[t] = 1;
        }
    }
    }
    
    
    for (auto& t : adj[x]) {
        if (t != y) {
            dfs2(t, x);
        } 
    }
    stor[T[x]].pop_back();
    ord.pop_back();
}

bool anc(int a, int b)
{
    return range[a].first <= range[b].first && range[b].second <= range[a].second;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen("atlarge.in", "r", stdin); freopen("atlarge.out", "w", stdout);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B), adj[B].push_back(A);
    }

    dfs(1, 0);

    for (int i = 0; i < M; i++)
    {
        cin >> dat[i][0] >> dat[i][1] >> C[i];
        for (int j = 0; j < 2; j++) {
            todo[dat[i][j]].push_back(i);
        }
    }

    dfs2(1, 0);

    for (int i = 0; i < M; i++)
    {
        if (ok[i])
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}