#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    int I,S,L,U;
    cin >> I >> S >> L >> U;
    vector < vector < pair<ll,ll> >> graph(I);

    for (int i = 0; i < S; i++){
        ll a,b,p;
        cin >> a >> b >> p;
        //cout << a << " "  << b << " "  << p << " " << I << endl;
        pair < ll , ll > c = {p,b};
        graph[a].push_back(c);
        pair < ll , ll > d = {p,a};
        graph[b].push_back(d);
    }
    priority_queue < pair < ll , ll> > heap;
    heap.push({0,0});
    //make_heap(heap.begin(),heap.end());
    vector < ll > ans(I, 100000);

    while (true ){
        pair < ll , ll >  c = heap.top();
        heap.pop();
        ll a = -c.first;
        ll b = -c.second;
        ans[a] = min(ans[a],b);
        cout << c.first << " " << c.second << " " << graph[a].size() << endl;
        for (int i = 0; i < graph[a].size(); i++){
            pair <ll,ll> pc = graph[a][i];
            ll p = pc.first;
            ll c = pc.second;
            cout << p << c << endl;
            if(ans[c] > p + b){
                heap.push({-c,-(p+b)});
            }
        }
        for (int i =0 ; i < I; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        break;
    }

    set < pair<ll,ll> > good;
    for (int i = 0; i < I; i++){
        if (ans[i] * 2 < U){
            for (int j = 0; j < graph[i].size(); j++){
                if (i < graph[i][j].second){
                    good.insert({i,graph[i][j].second});
                }
                else{
                    good.insert({graph[i][j].second,i});
                }
            }
        }
    }
    cout << good.size() << endl;
}
