#include <bits/stdc++.h>

using namespace std;

int N, M;
int types[10005];
vector<int> adj[10005];
int parent[10005];
int vis[10005];

int path[3][10005];

void dfs(int cur, int prev, int pathNumber, int ptr,
                             int node, bool &flag)
{
    for (int i=0; i< adj[cur].size(); i++)
    {
        if (adj[cur][i] != prev and !flag)
        {
            path[pathNumber][ptr] = adj[cur][i];
            if (adj[cur][i] == node)
            {
                flag = true;
 
                path[pathNumber][ptr+1] = -1;
                return;
            }
            dfs(adj[cur][i], cur, pathNumber, ptr+1,
                                        node, flag);
        }
    }
}

int lca(int a, int b)
{
    if (a == b)
        return a;
 
    path[1][0] = path[2][0] = 1;
 
    bool flag = false;
    dfs(1, 0, 1, 1, a, flag);
 
    flag = false;
    dfs(1, 0, 2, 1, b, flag);
 
    int i = 0;
    while (path[1][i] == path[2][i])
        i++;
 
    return path[1][i-1];
}

void dfs2(int n) {
    vis[n] = 1;

    for (auto& i : adj[n]) {
        if (vis[i] == 0) {
            parent[i] == n;
            dfs2(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen("atlarge.in", "r", stdin); freopen("atlarge.out", "w", stdout);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> types[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B), adj[B].push_back(A);
    }

    memset(vis, 0, sizeof(vis));

    dfs2(1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int l = lca(a, b);

        if (types[l] == c || types[a] == c || types[b] == c) {
            cout << 1;
            continue;
        }

        int found = 0;

        int cur = a;

        while (parent[cur] != l) {
            cur = parent[cur];
            if (types[cur] == c) {
                found = 1;
                break;
            }
        }

        if (found) {
            cout << 1;
            continue;
        }

        cur = b;

        while (parent[cur] != l) {
            cur = parent[cur];
            if (types[cur] == c) {
                found = 1;
                break;
            }
        }

        if (found) {
            cout << 1;
            continue;
        }

        cout << 0;
    }

    cout << endl;
}