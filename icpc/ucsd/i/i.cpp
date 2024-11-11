#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

ld dist(pair<ld,ld> a, pair<ld,ld> b){
    return sqrt(abs(a.first - b.first)* abs(a.first - b.first) + abs(a.second - b.second) * abs( a.second - b.second));
}
vector<vector<int>> graph;
bool connected(int x, int y){
    int n = graph.size();
    vector<int> stack = {x};
    unordered_set <int> visited;
    while (stack.size() > 0){
        int a = stack.back();
        stack.pop_back();
        visited.insert(a);
        for (int b = 0; b < n; b++){
            if (graph[a][b] == 0){
            continue;}
            if (visited.find(b) != visited.end()){
                continue;
            }
            stack.push_back(b);
        }

    if (visited.find(y) != visited.end()){return true;}
    return false;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<ld,ld>> lst;
    for (int i = 0; i < n; i++){
        ld a,b;
        cin >> a >> b;
        lst.push_back({a,b});
    }

    priority_queue <pair<ld,pair<ld,ld>>> k;
    for (int i=  0; i < n; i++){
        graph.push_back(vector<int>(n,0));
        for (int j = i+1; j < n; j++){
            k.push({-1 * dist(lst[i],lst[j]),{i,j}});
        }
    }



    for (int i0 = 0; i0 < n-1; i0 ++){
        int a,b,c;
        pair<ld,pair<ld,ld>> d = k.pop();
        a = d.a;
        b = d.b.a;
        c = d.b.b;
        while (connected(b,c)){
            pair<ld,pair<ld,ld>> d = k.pop();
            a = d.a;
            b = d.b.a;
            c = d.b.b;
        }

    }

}
