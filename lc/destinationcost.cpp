class Solution
{
public:
    vector<vector<int>> edges[1001];
    int cost[1001], time[1001];

    int traverse(int src, int dest, int maxTime)
    {

        for (int i = 1; i <= dest; i++)
        {
            cost[i] = INT_MAX;
            time[i] = INT_MAX;
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cost[src], time[src], src});

        while (pq.empty() == 0)
        {
            vector<int> z = pq.top();
            pq.pop();

            int c = z[0];
            int t = z[1];
            int v = z[2];

            for (int i = 0; i < edges[v].size(); i++)
            {

                if (t + edges[v][i][1] <= maxTime)
                {

                    if (cost[edges[v][i][0]] > c + edges[v][i][2])
                    {
                        cost[edges[v][i][0]] = c + edges[v][i][2];

                        time[edges[v][i][0]] = t + edges[v][i][1];
                        pq.push({cost[edges[v][i][0]], time[edges[v][i][0]], edges[v][i][0]});
                    }
                    else if (time[edges[v][i][0]] > t + edges[v][i][1])
                    {
                        time[edges[v][i][0]] = t + edges[v][i][1];
                        pq.push({c + edges[v][i][2], time[edges[v][i][0]], edges[v][i][0]});
                    }
                }
            }
        }

        return cost[dest];
    }

    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &fee)
    {
        int x, y, t, e = edges.size(), n = fee.size();

        for (int i = 0; i < e; i++)
        {
            x = edges[i][0];
            y = edges[i][1];
            t = edges[i][2];

            edges[x].push_back({y, t, fee[y]});
            edges[y].push_back({x, t, fee[x]});
        }

        cost[0] = fee[0];
        time[0] = 0;

        int ans = traverse(0, n - 1, maxTime);

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};