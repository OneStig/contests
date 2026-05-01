#include "bits/stdc++.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Usage: gen <n> <topology> <weight_dist> <max_w>
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    string topology = argv[2];      // "random", "star", "line", "caterpillar"
    string weight_dist = argv[3];   // "random", "identical", "exponential", "fibonacci", "heavy_one"
    long long max_w = atoll(argv[4]);

    vector<pair<int, int>> edges;

    // --- 1. GENERATE TOPOLOGY ---
    if (topology == "star") {
        for (int i = 2; i <= n; i++) edges.push_back({1, i});
    } 
    else if (topology == "line") {
        for (int i = 2; i <= n; i++) edges.push_back({i - 1, i});
    } 
    else if (topology == "caterpillar") {
        int spine_len = max(1, n / 2);
        for (int i = 2; i <= spine_len; i++) edges.push_back({i - 1, i});
        for (int i = spine_len + 1; i <= n; i++) {
            // Attach leaves randomly to the spine
            int attach_to = rnd.next(1, spine_len);
            edges.push_back({attach_to, i});
        }
    } 
    else { // "random"
        for (int i = 2; i <= n; i++) {
            edges.push_back({rnd.next(1, i - 1), i});
        }
    }

    // --- 2. GENERATE WEIGHTS ---
    vector<long long> weights(n - 1);
    if (weight_dist == "identical") {
        long long w = rnd.next(1LL, max_w);
        for (int i = 0; i < n - 1; i++) weights[i] = w;
    } 
    else if (weight_dist == "exponential") {
        long long w = 1;
        for (int i = 0; i < n - 1; i++) {
            weights[i] = w;
            w = min(w * 2, max_w); // Cap at max_w to prevent overflow
        }
    } 
    else if (weight_dist == "fibonacci") {
        if (n - 1 >= 1) weights[0] = 1;
        if (n - 1 >= 2) weights[1] = 2;
        for (int i = 2; i < n - 1; i++) {
            weights[i] = min(weights[i - 1] + weights[i - 2], max_w);
        }
    } 
    else if (weight_dist == "heavy_one") {
        weights[0] = max_w;
        for (int i = 1; i < n - 1; i++) weights[i] = 1;
    }
    else { // "random"
        for (int i = 0; i < n - 1; i++) weights[i] = rnd.next(1LL, max_w);
    }

    // --- 3. SHUFFLE VERTICES & EDGES TO PREVENT REVERSE ENGINEERING ---
    vector<int> perm(n + 1);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin() + 1, perm.end()); // Shuffle 1-indexed vertices

    // Shuffle the edge list and the weights so structural patterns aren't obvious in the input
    shuffle(edges.begin(), edges.end());
    shuffle(weights.begin(), weights.end());

    // --- 4. PRINT OUTPUT ---
    println(n);
    for (int i = 0; i < n - 1; i++) {
        int u = perm[edges[i].first];
        int v = perm[edges[i].second];
        if (rnd.next(2)) swap(u, v); // Randomize u, v order
        println(u, v, weights[i]);
    }

    return 0;
}
