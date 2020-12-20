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
	typedef int T;
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

	void clear(){
        s.assign(2*n, 0);
	}
};

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }


    vector<bool> l(n, false), r(n, false);

    Tree st(n);
    for(int i=0; i<n; i++){
        if(st.query(a[i], a[i]+1))
            break;

        st.update(a[i], 1);

        l[i] = (st.query(1, i+2) == i+1);

    }

    st.clear();
    for(int i=0, j=n-1; i<n; i++, j--){
        if(st.query(a[j], a[j]+1))
            break;

        st.update(a[j], 1);

        r[j] = (st.query(1, i+2) == i+1);

    }


    vector<pii> ans;
    for(int i=0; i<n-1; i++)
        if(l[i]&&r[i+1])
            ans.push_back({i+1, n-i-1});

    cout<<ans.size()<<"\n";
    for(auto k:ans)
        cout<<k.first<<" "<<k.second<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
5
1 4 3 2 1
*/
