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

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
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

vector<pii> a;
vector<ll> val;
vector<pii> b; //{cost, pos}
ll n, m;
string s;

bool comp(pii &a, pii &b){
    return a < b;
}

void solve(){
    a.clear(); b.clear(); val.clear();
    cin>>n>>m;
    for(int i = 0; i < n*m; i++){
        ll z; cin>>z;
        a.push_back({0, 0});
        val.push_back(z);
        b.push_back({z, i});
    }

    sort(all(b), comp);

    int row = 0;
    int column = 0;
    int current_pos = 0;
    for(auto [cost, pos] : b){
        a[pos] = {row, column};

        column++;
        if(column == m){
            row++;
            column = 0;
        }
    }

    vector<Tree> st(n, Tree(m+5));
    vector<unordered_map<ll, ll>> frecuency(n);

    ll ans = 0;
    int i = 0;
    for(auto [row, column] : a){
        //cout<<val[i]<<"\t"<<row<<" "<<column<<"\n";

        ans += st[row].query(0, column);
        ans -= frecuency[row][val[i]];

        st[row].update(column, 1);
        frecuency[row][val[i]]++;

        i++;
    }

    cout<<ans<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
3 2
1 1 2 2 3 3
*/
