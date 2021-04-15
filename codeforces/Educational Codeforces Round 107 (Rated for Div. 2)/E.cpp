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

#include <time.h>

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

#define MAX 300010
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
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

//char grid[MAX][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    vector<vector<char>> grid(n+1, vector<char>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin>>grid[i][j];
    }

    ull a(0), b(0);
    ull A(0), B(0);

    for(int i=1; i<=n; i+=2){
        for(int j=1; j<=n; j++){
            if(grid[i][j]=='o' && grid[i+1][j]=='o')
                a+=2;
            else if(grid[i][j] == 'o' || grid[i+1][j]=='o')
                A++;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j+=2){
            if(grid[i][j]=='o' && grid[i][j+1]=='o')
                b+=2;
            else if(grid[i][j] == 'o' || grid[i][j+1]=='o')
                B++;
        }
    }



}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

