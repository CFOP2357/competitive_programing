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
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

typedef ull ll;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = MOD; // change to something else
struct Mod {
	ll x;
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

vector<ull> a;
vector<ull> b;
ull n, k, q;

void solve(){
    a.clear(); b.clear();
    cin>>n>>k>>q;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    vector<Mod> contribution(n, Mod(0));

    for(int i=0; i<n; i++){
        for(int d = k; d>=1; d-=2){
            if(i+d-1<n){
                contribution[i] = contribution[i] + Mod(d)^( (k-d)/2  );
            }
            if(i-d+1<=0){
                contribution[i] = contribution[i] + Mod(d)^( (k-d)/2  );
            }
        }
    }

    Mod ans(0);

    for(int i=0; i<n; i++)
        ans = ans + contribution[i]*Mod(a[i]);

    while(q--){
        ull i, x; cin>>i>>x;
        ans = ans - contribution[i]*Mod(a[i]);
        a[i] = x;
        ans = ans + contribution[i]*Mod(a[i]);

        cout<<ans.x<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

