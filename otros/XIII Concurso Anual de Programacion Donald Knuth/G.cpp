//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 10000
#define MOD 515011997

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = MOD;
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod() : x(0) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

vector<ll> a;
vector<ll> b;
int n, m;
string s;

Mod fact[MAX];

Mod choose(int n, int k){
    Mod ans = fact[n] / (fact[k] * fact[n-k]);
    return ans;
}

void solve(){
    a.clear(); b.clear();
    cin>>m>>n;
    cin>>s;
    if(n > m)
        swap(n, m);

    map<char, int> frecuency;
    for(auto c : s)
        frecuency[c]++;

    vector<Mod> dp(n+1, Mod(0));
    dp[0] = Mod(1);

    for(auto &[c, k] : frecuency){
        auto dp2 = dp;
        for(int i = min(k, n); i > 0; i--){
            Mod ch = choose(k, i);
            for(int j = 0; j+i <= n; j++){
                dp2[j+i] = dp2[j+i] + (dp[j]*ch);
            }
        }
        dp = dp2;
    }


    Mod ans = dp[n] * fact[n] * fact[m];

    Mod di(n);
    di = di * Mod(m);

    ans = ans/di;

    cout<<ans.x<<"\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    fact[0] = Mod(1);
    for(ll i=1; i<MAX; i++){
        fact[i] = fact[i-1]*Mod(i);
    }

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

