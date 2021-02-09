#include <bits/stdc++.h>

using namespace std;

struct Item
{
    bool ifil;
    vector<Item *> chiln;
    int nl, nleaf;
    long long dist, tot;
};

Item nodes[100000];

int n, nlvs;

void first(Item *node)
{
    node->nleaf = (node->ifil ? 1 : 0);
    node->dist = 0;
    for (Item *ch : node->chiln)
    {
        first(ch);
        node->nleaf += ch->nleaf;
        node->dist += ch->dist + ch->nleaf * ch->nl;

        if (ch->ifil) {
            node->dist += ch->nl;
        }
    }
}

void dfs(Item *node, long long pln)
{
    node->tot = pln + node->dist;

    long long plenadd = 0;
    for (Item *ch : node->chiln)
    {
        plenadd += ch->dist + ch->nleaf * (ch->nl + (ch->ifil ? 0 : 1));
    }
    for (Item *ch : node->chiln)
    {
        dfs(ch, pln + plenadd -
        (ch->dist + ch->nleaf *
            ch->nl + (ch->ifil ? 0 : 1))) + 3 * (nlvs - ch->nleaf));
    }
}

int main()
{
    cin >> n;
    String name;
    int childs;
    nlvs = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        nodes[i].nl = strlen(name);
        nodes[i].ifil = false;

        cin >> childs;

        if (childs != 0)
        {
            nodes[i].ifil = true;
            nleavaes++;
        }
        for (int j = 0; j < childs; j++)
        {
            int id;
            cin >> id;
            nodes[i].chiln.push_back(&nodes[id - 1]);
        }
    }

    first(&nodes[0]);
    dfs(&nodes[0], 0);

    long long sol = 0;

    for (int i = 0; i < n; i++)
    {
        if (!nodes[i].ifil)
        {
            sol = max(sol, nodes[i].tot);
        }
    }
    cout << sol << endl;
}