#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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

#define MAX 1000100
#define MOD 1000000007

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
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
ull n, x, pos;
ull high, low;

void bS(){
    int l = 0;
    int r = n;
    while(l<r){
        //cout<<l<<" "<<r<<"\n";
        int m = (l+r)/2;
        //cout<<m<<"#\n";
        if(m<=pos){
            l = m+1;
            low++;
        }
        else {
            r = m;
            high++;
        }
    }
}

Mod fact(ull n){
    Mod ans(1);

    for(Mod i(2); i.x<=n; i = i+1)
        ans = ans*i;

    return ans;
}

Mod choose(ull n, ull k){
    Mod ans = fact(n) / (fact(n-k));

    return ans;
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>x>>pos;

    high=0, low=0;

    bS();

    //cout<<low<<" "<<high<<"\n";

    if(low>x || high > n-x){
        cout<<"0\n";
        return;
    }

    Mod ans = choose(x-1, low-1) * choose(n-x, high) * fact(n-(high+low));

    cout<<ans.x<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

