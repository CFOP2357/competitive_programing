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


#define MAX 200100
#define MOD 998244353

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = MOD; // change to something else
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

Mod fact[MAX];

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

Mod choose(ll n, ll k){
    if(k > n)
        return Mod(0);
    return fact[n] / (fact[k] * fact[n-k]);
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    map<int, int> frecuency;
    for(int i = 0; i < n; i++){
        ll z; cin>>z;
        a.push_back(z);

        frecuency[z]++;
    }
    sort(all(a));

    if(frecuency[a.back()] > 1)
        cout<<fact[n].x<<"\n";
    else {
        ll k = frecuency[a.back()-1];
        Mod ans = 0;

        for(ll s = n-2; s >= 0; s--){
            ans = ans + ((choose(n-1, k) - choose(s, k)) * fact[k] * fact[n-k-1]);
        }

        cout<<ans.x<<"\n";
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    fact[0] = Mod(1);
    for(ll i = 1; i < MAX; i++)
        fact[i] = fact[i-1] * Mod(i);

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

