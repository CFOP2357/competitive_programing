//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

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

ofstream fout ("out.txt");
ifstream fin ("in.txt");


#define MAX 1000100
#define MOD 1000000007

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

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    fin>>n;
    fin>>s;

    s = "F" + s;

    vector<Mod> sum;
    sum.push_back(0);

    Mod ans;

    int last_O_idx = 0;
    int last_X_idx = 0;
    char current_hand = 'O';
    for(int i = 1; i <= n; i++){
        if(s[i] != 'F')
            current_hand = s[i];

        if(current_hand == 'O'){
            if(s[i] != 'F')
                last_O_idx = i;

            sum.push_back(Mod(last_X_idx) + sum[last_X_idx]);
            ans = ans + sum.back();
        }
        else {
            if(s[i] != 'F')
                last_X_idx = i;

            sum.push_back(Mod(last_O_idx) + sum[last_O_idx]);
            ans = ans + sum.back();
        }
    }

    fout<<ans.x<<"\n";
}


int main(){
    //srand (time(NULL));

    ull T = 1;
    int t=1; fin>>t;
    while(t--){
        fout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

