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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 10010
#define MOD 1000000007

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

const long long mod = MOD; // change to something else
struct Mod {
	int x;
	Mod(ll xx) : x(xx) {}
	Mod() : x(0) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod(((long long)x * (long long)b.x) % mod); }
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

int dp[MAX][MAX]; //n, sum [0, A]

void solve(){
    ull n, a, b;
    cin>>n>>a>>b;
    if(a>n){
        cout<<"0\n";
        return;
    }
    b = min(b, n);

    Mod ans = Mod(dp[n][b]) - Mod(dp[n][a-1]);
    cout<<ans.x<<"\n";

}

const ll MAXN = MAX;
Mod factorial[MAXN];
Mod inverse_factorial[MAXN];


Mod comb(ll n, ll k) {
  Mod ans = factorial[n]
  * inverse_factorial[k]
  * inverse_factorial[n - k];

  /*if(ans.x != (factorial[n] / (factorial[k] * factorial[n - k])).x ){
    cout << n << ' ' << k << '\n';
    cout << ans.x << " " << (factorial[n] / (factorial[k] * factorial[n - k])).x<<"\n";
}*/
  return ans;
}

void pre(){
    factorial[0] = 1;
    inverse_factorial[0] = 1;
    for(ll i = 1; i<MAX; i++){
        factorial[i] = factorial[i-1] * Mod(i);
        inverse_factorial[i] = factorial[i]^(MOD - 2);
    }

    /*for(int i = 0; i<=10; i++)
      cout<< comb(10,i).x<<" ";
    cout<<"\n";*/

    for(ll i=0; i<MAX; i++){
        dp[i][0] = 0;
        for(ll j = 1; j<MAX; j++){
            dp[i][j] = dp[i][j-1] + comb(i, j).x;
            if(dp[i][j]>=MOD)
                dp[i][j]-=MOD;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    pre();

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
5
4 3 3
8 5 5
7 5 6
9 2 5
7 5 6

1
1 1 1

1

*/
