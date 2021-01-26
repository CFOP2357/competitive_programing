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

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef ull ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 200010
#define MOD 998244353

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = MOD; // change to something else
struct Mod {
	ll x;
	Mod() : x(0) {}
	Mod(ll xx) : x(xx) {}
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
Mod pot[MAX];

Mod choose(Mod n, Mod k){
    return fact[n.x]/(fact[k.x] * fact[(n-k).x]);
}

vector<ull> a;
vector<ull> b;
ull n, m;

void solve(){
    cin>>n>>m;

    Mod ans(0);

    for(ull i=n-1; i<=m; i++){
        ans = ans + Mod(i-1) * choose(i-2, n-3) * pot[n-3];
        //cout<<ans.x<<" ";
    }

    cout<<ans.x<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    fact[0] = Mod(1);
    for(ull i=1; i<MAX; i++)
        fact[i] = fact[i-1] * i;

    pot[0] = Mod(1);
    for(ull i=1; i<MAX; i++)
        pot[i] = pot[i-1] * Mod(2);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

