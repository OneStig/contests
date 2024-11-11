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



vector<int> AllDeck;
vector<int> cards;
map<vector<int>, ld> cache;
ld zero = 0;
ld one = 1;
ld solve(vector<int> deck, vector<int> seen){

    if (cache.find(deck) != cache.end()){
        return cache[deck];
    }
    int c = 0;
    int s = 0;
    for (int i = 0; i < 8; i++){
        c += deck[i];
        s += seen[i];
    }
    if (c == 0 or s >= 7){
        cache[deck] = zero;
        return zero;
    }
    //dbg(deck);
    //dbg(seen);
    ld ans = 0;
    for (int i = 0; i < 8; i++){
        if (deck[i] == 0){
            continue;
        }
        ld p = (deck[i] + zero)/(c + zero);
        deck[i] -= 1;
        if (seen[i] == 1 or i == 7){
            ans += p * (1 + solve(deck,seen));
        }
        else{
            vector<int> change;
            int stack = i;
            while (0 <= stack and stack <= 6 and seen[stack] == 0){
                seen[stack] = 1;
                change.push_back(stack);
                stack = cards[stack];
            }
            ans += p * (solve(deck,seen) + 1);
            for (auto b : change){
                seen[b] = 0;
            }
        }
        deck[i] += 1;
    }
    cache[deck] = ans;
    //dbg(deck,seen,ans,cards,c);
    return ans;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (char i : s){
        if (i == 'A'){cards.push_back(0);}
        else if (i == '2'){cards.push_back(1);}
        else if (i == '3'){cards.push_back(2);}
        else if (i == '4'){cards.push_back(3);}
        else if (i == '5'){cards.push_back(4);}
        else if (i == '6'){cards.push_back(5);}
        else if (i == '7'){cards.push_back(6);}
        else{cards.push_back(7);}


    }
    vector<int> deck = {4,4,4,4,4,4,4,24};
    for (int j : cards){
        deck[j] -= 1;
    }
    vector<int> seen = {0,0,0,0,0,0,0,0};
    cout << fixed << setprecision (9) << solve(deck,seen) << "\n";
}
