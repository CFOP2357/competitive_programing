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
	T f(T a, T b) {
	    if(!a)
            return b;
        if(!b)
            return a;
	    return __gcd(a, b);
    } // (any associative fn)
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
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    set<pii> current; //val, pos
    Tree st(2*n+10); const int N = 2*n+10;
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        a.push_back(z);
    }

    ll i = 0, j = 0;
    ll ans = 1;
    current.insert({a[0], 0});
    while(j<n){
        ll G = st.query(0, N);
        if(i==j or G>=2 or !G){ //possible
            ans = max(ans, j-i+1);
            j++;
            if(j<n){
                auto r = current.upper_bound({a[j], 0});
                auto l = r;
                if(l!=current.begin())
                    l--;
                else l = current.end();

                if(r!=current.end()){
                    st.update(2*j + 1, abs(r->first - a[j]));
                    st.update(2*r->second, abs(r->first - a[j]));
                }
                else st.update(2*j + 1, 0);

                if(l!=current.end()){
                    st.update(2*j, abs(l->first - a[j]));
                    st.update(2*l->second + 1, abs(l->first - a[j]));
                }
                else st.update(2*j, 0);

                current.insert({a[j], j});
            }
        }
        else { //not possible
            current.erase({a[i], i});

            auto r = current.upper_bound({a[i], 0});
            auto l = r;
            if(l!=current.begin())
                l--;
            else l = current.end();

             st.update(2*i, 0);
             st.update(2*i + 1, 0);

             if(r==current.end()){
                if(l!=current.end()){
                    st.update(2*l->second + 1, 0);
                }
             }
             else if(l==current.end()){
                if(r!=current.end()){
                    st.update(2*r->second, 0);
                }
             }
             else {
                st.update(2*l->second + 1, abs(l->first - r->first));
                st.update(2*r->second, abs(l->first - r->first));
             }

             i++;
        }
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

