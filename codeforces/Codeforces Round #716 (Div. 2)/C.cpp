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

#define MAX 200010
#define MOD 1000000007

ull n, m;
string s;

ull D[MAX];

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

bool isPrime(ull n){

    for(ull i=2; i*i<=n; i++)
        if(n%i == 0)
            return false;
    return true;

}

void solve(){
    cin>>n;

    mod = n;

    vector<ull> ans(1, 1);
    for(ull i=1; i<n; i++){

        if(__gcd(n, i) != 1)
            continue;

        cout<<i<<" "<<Mod(i).invert(i).x<<"\n";

        vector<ull> currentAns(1, 1);
        map<ull, ull> selected;

        Mod p(n);
        ull inv = p.invert(i).x;

        ull d = (i*inv)/__gcd(i, inv);
        while(d>1){
            selected[D[d]]++;
            d /= D[d];
        }

        d = inv;
        while(d>1){
            selected[D[d]]++;
            d /= D[d];
        }

        for(auto &p : selected){
            currentAns.push_back(p.first); p.second--;
        }

        for(auto &p : selected){
            if(!p.second) continue;
            for(auto &k : selected){
                if(p.first == k.first)
                    continue;
                if(!k.second || !p.second) continue;
                currentAns.push_back(p.first*k.first);
                p.second--;
                k.second--;
            }
        }

        if(currentAns.size() > ans.size())
                ans = currentAns;

    }

    sort(all(ans));
    cout<<ans.size()<<"\n";

    for(auto a : ans)
        cout<<a<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    for(ull i = 2; i<MAX; i++){

        if(D[i])
            continue;
        for(ull j = i; j<MAX; j+=i)
            D[j] = i;
    }

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

