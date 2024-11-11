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
string s;
int find(int l, int r, char a, char b, int iteration){
    if (l == r) {
        return 1;
    }
    if(l > r){
        return 2;
    }

    char aaa,bbb;
    aaa = s[l];
    bbb = s[r];
    s[l] = a;
    s[r] = b;
    bool exist = false;
    int ans = 1e9;
    vector<pair<int,int>> good;
    for(int i = l; i < r-1; ++i){


        if((s[i] == 'W' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'W')){
            int k1,k2,k3,k4;
            int r1,r2;
            k1 = 1-find(l, i - 1, a, s[i-1],1);
            k2 = ((1-find(i + 1, r, s[i], b,1)));
            k3 = (1-find(l, i, a, s[i+1],1));
            k4 = (1-find(i + 2, r, s[i+2], b,1));
            dbg(k1,k2,k3,k4);
            if (k1 == k2) {
                r1 = 1 - k1;
            }
            else if (k1 == -1 and k2 == -1) {
                r1 = 0;
            }
            else if (k1 == -1 or k2 == -1) {
                r1 = k1 + k2 + 1;
            }
            else {
                r1 = k1 + k2;
            }
            if (k3 == k4) {
                r2 = 1 - k3;
            }
            else if (k3 == -1 and k4 == -1) {
                r2 = 0;
            }
            else if (k3 == -1 or k4 == -1) {
                r2 = k3 + k4 + 1;
            }
            else {
                r2 = k3 + k4;
            }
            dbg(r1,r2,s[i],s[i+1]);
            if (r1 < ans) {
                good = {{i,i+1}};
                ans = r1;
            }
            else if (r1 == ans) {
                good.push_back({i,i+1});
            }
            if (r2 < ans) {
                good = {{i+1,i}};
                ans = r1;
            }
            else if (r2 == ans) {
                good.push_back({i+1,i});
            }
            exist = true;
        }


    }
    if (iteration == 0) {
        for (auto i : good) {
            cout << i.first << " " << i.second << "\n";
        }
    }
    dbg(s,l,r,a,b,ans,exist);
    s[l] = aaa;
    s[r] = bbb;
    if(!exist){
        return 1;
    }
    else{
        return ans;
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin >> s;
    s += '.';
    vector<vector<int>> comps;
    vector<int> comp;
    for (int i = 0; i < n+1; i++) {
        if (s[i] == '.') {
            comps.push_back(comp);
            comp = {};
        }
        else {
            comp.push_back(i);
        }
    }
    int ans = 0;
    for (auto c : comps) {
        if (c.size() == 0) {
            continue;
        }
        ans = ans ^ find(c[0],c[c.size() - 1],s[c[0]],s[c[c.size() - 1]],0);
    }
    cout << ans << "\n";
}
