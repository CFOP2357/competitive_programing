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

#define MAX 1000100
#define MOD 1000000007

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll mod;
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

vector<Mod> ans{1, 1, 2, 6, 20};
ull n, m;

Mod segment_ans(int k){
    Mod sum(1);
    for(int i=0; i<k-2; i++){
        sum = sum + Mod(i+1)*ans[k-i-1];
    }
    return sum;
}

void solve(){
    cin>>n>>mod;

    for(int i=5; i<=n; i++){

        ans.push_back(0);
        for(int j=1; j<=i; j++){
            Mod p = segment_ans(j-1);
            //cout<<p.x<<" ";
            Mod p2 = segment_ans(i-j);
            p = (Mod(max(j-1, i-j))^min(j-1, i-j)) * p * p2;
            //cout<<p2.x<<" ";
            //cout<<p.x<<"\n";
            ans[i] = ans[i] + p;
        }

    }

    cout<<ans[n].x<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*

5 1000000007
6 1000000007
7 1000000007
8 1000000007
9 1000000007
10 1000000007
*/
