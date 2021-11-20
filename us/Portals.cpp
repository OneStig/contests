#include <bits/stdc++.h>

using namespace std;

struct node
{
    int c;
    int portal[4];
    int comp1 = -1;
    int comp2 = -1;
};

bool nodec(node a, node b)
{
    return a.c < b.c;
}
vector<node> graph;
void floodlist(int pos, int mark, int bin)
{

    if (bin == 0) {
        graph[pos].comp1 = mark;
    }
    else if (bin == 2) {
        graph[pos].comp2 = mark;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int next : pedge.find(graph[pos].portal[i + bin])->second)
        {
            if (next == pos)
                continue;

            int compmake;

            for (int j = 0; j < 4; j++) {
                if (graph[next].portal[j] == graph[pos].portal[i + which]) {
                    compmake = j;
                }
            }
            
            
            if (compmake < 2)
                compmake = 0;
            else
                compmake = 2;
            if (compmake == 0 && graph[next].comp1 == -1)
                floodlist(next, mark, compmake);
            if (compmake == 2 && graph[next].comp2 == -1)
                floodlist(next, mark, compmake);
        }
    }
}

unordered_map<int, vector<int>> pedge int n;
int n;

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        node temp;
        cin >> temp.c;
        
        for (int j = 0; j < 4; j++)
        {
            cin >> temp.portal[j];
        }

        graph.pb(temp);
        lp(j, 4)
        {
            if (pedge.find(temp.portal[j]) == pedge.end())
            {
                pedge.insert({temp.portal[j], {i}});
            }
            else
            {
                pedge.find(temp.portal[j])->second.pb(i);
            }
        }
    }
    int comp = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i].comp1 == -1)
        {
            floodlist(i, comp, 0);
            comp++;
        }
        if (graph[i].comp2 == -1)
        {
            floodlist(i, comp, 2);
            comp++;
        }
    }

    sort(graph.begin(), graph.end(), nodec);

    int ans = 0;
    int link[MAXN];
    int size[MAXN];
    
    for (int i = 0; i < comp; i++)
    {
        link[i] = i;
        size[i] = 1;
    }
    for (auto it : graph)
    {
        int fst = it.comp1;

        while (fst != link[fst]) {
            fst = link[fst];
        }

        int scd = it.comp2;

        while (scd != link[scd]) {
            scd = link[scd];
        }     

        if (fst != scd)
        {
            if (size[fst] < size[scd])
                swap(fst, scd);
            ans += it.c;
            size[fst] += size[scd];
            link[scd] = fst;
        }
    }

    cout << ans << endl;
}