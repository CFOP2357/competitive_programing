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
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

struct Tree {
	typedef ull T;
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

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    map<int, int> val;
    for(int i=1; i<=m; i++){
        ull z; cin>>z;
        b.push_back(z);
        val[z]=i;
    }
    for(auto &order : a)
        order = val[order];

    vector<ull> cost(n, 0);
    Tree st(n+1);
    for(int i=n-1; i>=0; i--){
        if(st.query(1, a[i]))
            cost[i] = 1;
        st.update(a[i], 1);
    }
    Tree st2(n+1);
    ull ans = 0;
    ull p=0;
    for(int i=0; i<n; i++){
        st2.update(a[i], 1);
        if(!cost[i]){
            ull k = st2.query(a[i]+1, n+1) + p;
            cost[i] = 2*k+1;
        }
        if(a[i])
            ans+=cost[i];
        else
            p++;
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

