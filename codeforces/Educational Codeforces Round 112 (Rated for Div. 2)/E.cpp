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
typedef int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

const ll inf = INT_MAX; //no debe ser posible que un valor llegue a inf para que funcione el segment
template<typename T> struct ST {
    T lo, hi;
    ST *l = 0, *r = 0;

    /////////////cambia esto
	T empty_add = 0; //valor unitario, no agrega nada con add
	T add_operation(const T &a, const T &b){
        return a+b;
    }
    T not_ = INT_MAX; //valor vacio, no cambia nada con query
    T query_operation(const T &a, const T &b){
        return min(a, b);
    }
    /////////////

    T mset = inf, madd = empty_add, val = 0;

	ST(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	ST(vi& v, int lo, int hi) : lo(lo), hi(hi) { //[lo, ho)
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new ST(v, lo, mid); r = new ST(v, mid, hi);
			val = query_operation(l->val, r->val);
		}
		else val = v[lo];
	}

	T query(int L, int R) { //[L, R)
		if (R <= lo || hi <= L) return not_;
		if (L <= lo && hi <= R) return val;
		push();
		return query_operation(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, T x) { //[L,R)
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = empty_add;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = query_operation(l->val, r->val);
		}
	}
	void add(int L, int R, T x) { //[L, R)
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset = add_operation(mset, x);
			else madd = add_operation(madd, x);
			val = add_operation(val, x);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = query_operation(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new ST(lo, mid); r = new ST(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd != empty_add)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = empty_add;
	}
};


vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    cin>>n>>m;

    vector<pair<ll, pii>> segments;
    for(int i=0; i<n; i++){
        ll l, r, w; cin>>l>>r>>w;
        segments.push_back({w, {2*l, 2*r}});
    }
    sort(all(segments));

    vector<ll> init(2*m+5, 0);
    ST<ll> st(init, 0, init.size());

    ll ans = INT_MAX;
    int i=0, j=0;

    st.add(segments[0].second.first, segments[0].second.second+1, 1);
    while(j<n){
        if(st.query(2, 2*m+1)>0){ //possible
            if(i==j){
                ans = 0;
                break;
            }
            ans = min(ans, segments[j].first - segments[i].first);

            st.add(segments[i].second.first, segments[i].second.second+1, -1);
            i++;
        }
        else{
            j++;
            st.add(segments[j].second.first, segments[j].second.second+1, 1);
        }
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

