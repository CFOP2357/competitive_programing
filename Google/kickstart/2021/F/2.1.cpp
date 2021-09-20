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

ull n, D, k;

struct Attraction{
        priority_queue<ll, vector<ll>, greater<ll>> current;
        ll sum = 0;
};

const Attraction inf = {priority_queue<ll, vector<ll>, greater<ll>>(), LLONG_MAX}; //no debe ser posible que un valor llegue a inf para que funcione el segment
template<typename T> struct ST {
    T lo, hi;
    ST *l = 0, *r = 0;

    /////////////change this
	T empty_add; //valor unitario, no agrega nada con add
	T not_; //valor vacio, no cambia nada con query
	T add_operation(T a, T b){
        priority_queue<ll, vector<ll>, greater<ll>> new_current;
        while(a.current.size()){
            new_current.push(a.current.top());
            a.current.pop();
        }
        while(b.current.size()){
            new_current.push(b.current.top());
            b.current.pop();
        }

        ll sum = a.sum + b.sum;

        while(new_current.size() > k){
            sum -= new_current.top();
            new_current.pop();
        }

        return {new_current, sum};
    }
    T query_operation(T a, T b){
        priority_queue<ll, vector<ll>, greater<ll>> new_current;
        while(a.current.size()){
            new_current.push(a.current.top());
            a.current.pop();
        }
        while(b.current.size()){
            new_current.push(b.current.top());
            b.current.pop();
        }

        ll sum = a.sum + b.sum;

        while(new_current.size() > k){
            sum -= new_current.top();
            new_current.pop();
        }

        return {new_current, sum};
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
			val += x*(hi-lo);
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

void solve(){
    cin>>D>>n>>k;

    vector<ll> init(D+5, 0);
    ST<ll> st(init, 0, D+5);

    for(int i=0; i<n; i++){
        ll h, s, e; cin>>h>>s>>e;
        st.add(s, e+1, h);
    }

    ll ans = st.query(0, D+1);
    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


