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


#define MAX 1000100
#define MOD 1000000007

map<ll, bool> a;
map<ll, bool> b;
map<ll, bool> c;
ll k1,k2,k3;
ll n;
string s;

struct Tree {
	typedef ll T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve(){
    a.clear(); b.clear();
    cin>>k1>>k2>>k3;
    n = k1+k2+k3;
    for(int i=0; i<k1; i++){
        ll z; cin>>z;
        a[z]=true;
    }
    for(int i=0; i<k2; i++){
        ll z; cin>>z;
        b[z]=true;
    }
    for(int i=0; i<k3; i++){
        ll z; cin>>z;
        c[z]=true;
    }

    Tree cost(n+1);
    ll current_cost = b.size();
    cost.update(0, b.size());
    for(int i=1; i<=n; i++){
        if(b[i])
            current_cost--;
        if(c[i])
            current_cost++;
        cost.update(i, current_cost);
    }

    ll ans = n;
    current_cost = a.size();
    for(int i=0; i<=n; i++){
        if(a[i])
            current_cost--;
        if(b[i])
            current_cost++;
        ans = min(current_cost+cost.query(i, n+1), ans);
    }

    cout<<ans<<"\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

