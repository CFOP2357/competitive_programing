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

vector<ll> a;
vector<ll> b;
ll n, m, q;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>q;
    Tree st1(n+1);
    Tree st2(n+1);
    Tree st(n+1);

    int mult = 1;
    cin>>s;
    for(int i = 0; i < n; i++){
        int charge = 0;
        if(s[i]=='+')
            charge++;
        else
            charge--;

        if(i%2)
        st1.update(i, charge*mult);
        else
        st2.update(i, charge*mult);

        st.update(i, charge*mult);

        cout<<charge*mult<<" ";

        mult *= -1;
    }cout<<"\n";

    while(q--){
        int l, r; cin>>l>>r;
        cout<<st1.query(l-1, r)<<" "<<st2.query(l-1, r)<<" "<<st.query(l-1, r)<<"#\n";

        /*if(1)
            cout<<st.query(l, r+1)/2<<"\n";
        else
            cout<<st.query(l, r+1)<<"\n";*/
        //cout<<min(abs(st1.query(l, r+1)), abs(st2.query(l, r+1)))<<"\n";
    }

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
12 1
--++---++---
1 12

1
14 1
+--++---++-++-
1 14

1
14 3
+--++---+++---
1 14
6 12
3 10
*/
