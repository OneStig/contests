#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int max_n = 200000; 
    long long max_w = 1000000000LL;

    int n = inf.readInt(1, max_n, "n");
    inf.readEoln();

    DSU dsu(n);

    for (int i = 0; i < n - 1; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readSpace();
        long long w = inf.readLong(1LL, max_w, "w");
        inf.readEoln();

        ensuref(dsu.unite(u, v), "Graph contains a cycle or parallel edges!");
    }
    
    inf.readEof();
    return 0;
}
