#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include "math.h"
#include "assert.h"
 
using namespace std;
 
#define fast_input ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define epsilon 1e-07
#define pi 2 * acos(0.0);
#define mod 1000000007   // 1e9+7
 
#define inf std::numeric_limits<int>().max()
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    vector<string> v;
    for(int i=1; i<=10000; i++) {
        string str = to_string(i);
        char c = str[0];
        bool vf = true;
        for(int j=0; j<str.size(); j++) {
            if (c != str[j]) vf = false;
        }
        if (vf) {
            v.push_back(str);
        }
    }
    sort(v.begin(), v.end());
    
    int t = 1;
    while (t--) {
        int x = 11;
        int ans = 0;
        
        for(int i=0; i<v.size() && v[i] <= to_string(x); i++) {
            ans += v[i].size();
        }
        cout << ans << endl;
    }
}