#include <bits/stdc++.h>

using namespace std;

/* TYPES  */
#define tcT template <class T
#define tcTU tcT, class U
#define tcTUW tcTU, class W
using ll = long long;
using db = long double;
using str = string;

/* PAIRS */
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

/* VECTORS */
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vvi = V<V<int>>;
using vb = V<bool>;
using vl = V<ll>;
using vvl = V<V<ll>>;
using vd = V<db>;
using vc = V<char>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
#define sz(x) int(size(x)) // (ll)(x).size()
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define view(x, a) V<decltype(x)::value_type> (bg(x), bg(x)+a+1)
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define lb lower_bound
#define ub upper_bound
#define sum(v) accumulate(all(v), 0ll)

/* UNORDERED MAP SET */
#define timeStamp() std::chrono::steady_clock::now()
struct custom_hash {static uint64_t xs(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);} size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = timeStamp().time_since_epoch().count(); return xs(x + FIXED_RANDOM);} size_t operator()(const pl& p) const {static const uint64_t FIXED_RANDOM = timeStamp().time_since_epoch().count(); return xs((uint64_t)p.fi) + ((uint64_t)p.se) * FIXED_RANDOM;}};

tcTU > using UM = unordered_map<T, U, custom_hash>;
tcT > using US = unordered_set<T, custom_hash>;
using umll = UM<ll, ll>;
using umcl = UM<char, ll>;
using umsl = UM<str, ll>;

using usl = US<ll>;
using usc = US<char>;
using uss = US<str>;
#define has(s, x) (s.find(x) != end(s))

/* LOOPS */
#define FOR(i, s, e) for (ll i = (s); i < (e); ++i)
#define CFOR(i, s, e) for (ll i = (s); i <= (e); ++i)
#define ROF(i, e, s) for (ll i = (e)-1; i >= (s); --i)
#define each(a, x) for (auto &a : x)
#define eachkv(k, v, mp) for (auto &[k, v] : mp)

/* CONSTANTS */
const char nl = '\n';
const int MOD = 998244353;  // 1e9+7;
const int MX = (int)2e6 + 5;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int dr[4]{1, -1, 1, -1}, dc[4]{1, 1, -1, -1};  // for every diagonal problem!!
mt19937 rng((uint32_t)timeStamp().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

/* FUNCTIONS */
tcT > UM<T, ll> counter(V<T> &v){ UM<T, ll> mp; each(a, v){ if (mp.count(a)){mp[a]++;} else{mp[a] = 1;}	} return mp;}
UM<char, ll> counter(str &v){ UM<char, ll> mp; each(a, v){ if (mp.count(a)){mp[a]++;} else{mp[a] = 1;}	} return mp;}
tcTU > V<pair<T, U>>  keyvals(UM<T, U> &mp){V<pair<T, U>> vp; eachkv(k,v,mp){vp.eb(k, v);} return vp;}
tcT > V<T> idxter(V<T> v){V<T> idxs(MX, -1);FOR(i,0,sz(v)){idxs[v[i]] = i;}return idxs;}

tcT > void remDup(V<T> &v) {sort(all(v));	v.erase(unique(all(v)), end(v));}
tcTU > void ese(T &t, const U &u) {auto it = t.find(u); t.erase(it);}
// [](const auto& a, const auto& b) {return a.se < b.se;}

/* TESTING */
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); // cout.tie(NULL);
#define rd(...) ([](auto&&... args) { (cin >> ... >> args); }(__VA_ARGS__))
#define rdv(v) each(x, v) { rd(x);}
#define wrtl(...) ([](auto&&... args) { (cout << ... << args) << endl; }(__VA_ARGS__))
#define YES wrtl("YES")
#define NO wrtl("NO")

vl dp(MX, 0);
// vvl dp(m, vl(n, 0)); // m x n

void solve(){
	str s; rd(s);
	ll n = sz(s);

	FOR(i,0,n-1){
		if (s[i] == 'O' && s[i+1] == 'O'){
			cout << "INVALID" << nl;
			return;
		}
	}
	reverse(all(s));

	ll res = (1ll << 48) + 1;
	ll tmp;
	for(ll i = 4; i <= (1ll << 60); i*=2){
		tmp = i;
		// dbg(tmp);
		FOR(j,0,n){
			if(s[j] == 'E'){
				tmp *= 2;
				if (tmp >= (1ll << 62)){ // 63 is negative
					tmp = 0;
					break;
				}
			} else if(s[j] == 'O'){
				if ((tmp-1) % 3 != 0){
					// dbg("not divis");
					tmp = 0;
					break;
				}
				tmp = (tmp-1)/3;

				// maybe not?
				// if (tmp >= (1ll << 62)){
				// 	tmp = 0;
				// 	break;
				// }
			}
		}
		// dbg(tmp);
		if (tmp != 0 && (res > tmp)){
			res = tmp;
		}

	}

	cout << (res == ((1ll << 48) + 1) ? "invalid" : res) << nl;
}

int main(){
   fastio;

   ll t = 1;
//    cin >> t;

   while(t--){
      solve();
   }

   return 0;
}
