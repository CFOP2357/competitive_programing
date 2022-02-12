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

#include <assert.h>

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
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return __gcd(a, b); } // (any associative fn)
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

struct TreeSum {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	TreeSum(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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


#define MAX 200100
#define MOD 1000000007

vector<pii> b;
ll n, m;
string s;

Tree st(MAX);

int get_r(int L, int l, int r){
    if(l+1 >= r)
        return l;

    int m = (l+r)/2;
    if(st.query(L, m+1) >= (m-L+1))
        return get_r(L, m, r);
    return get_r(L, l, m);
}

void solve(){
    b.clear();
    cin>>n;
    for(int i = 1; i <= n; i++){
        ll z; cin>>z;
        st.update(i, z);
    }

    for(int l = 1; l <= n; l++){
        int r = get_r(l, l, n+1);

        //cout<<l<<" "<<r<<"#\n";

        if((r - l + 1) == st.query(l, r+1))
            b.push_back({r, l});
    }

    sort(all(b));

    TreeSum st_sum(n+1);
    int current_r = 0;
    for(auto [r, l] : b){
        if(l <= current_r)
            continue;

        st_sum.update(r, st_sum.query(r, r+1) + 1);
        current_r = r;
    }

    for(int i = 1; i <= n; i++)
        cout<<st_sum.query(0, i+1)<<" ";
    cout<<"\n";

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

