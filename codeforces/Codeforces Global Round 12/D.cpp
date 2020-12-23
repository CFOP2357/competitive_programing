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

vector<ull> a;
vector<ull> b;
ull n;

struct Tree {
	typedef bool T;
	static constexpr T unit = true;
	T f(T a, T b) { return a && b; } // (any associative fn)
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

    cin>>n;
    b.assign(n+1, 0);

    Tree st(n+1);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        b[z]++;
    }

    for(int i=1; i<=n; i++)
        st.update(i, b[i]==1);

    stack<pii> last; //value, pos
    vector<vector<int>> kill(n+1, vector<int>());
    vector<ull> l(n+1, -1), r(n+1, n);
;

    for(ull i=0; i<n; i++){

        while(last.size() && last.top().first>=a[i]){
            r[last.top().second] = i;
            last.pop();
        }

        if(last.size()){
            l[i] = last.top().second;
        }

        last.push({a[i], i});

    }

    for(int i=0; i<n; i++){
        ull d = r[i] - l[i] - 1;
        d = n - d;

        //cout<<r[i]<<" ";

        if(d<=n && d>=0)
            kill[d].push_back(a[i]);

    } //cout<<"\n";

    for(int i=n; i>0; i--){

        for(int z : kill[i]){
            b[z]--;
            st.update(z, b[z]==1);
        }

        cout<<st.query(1, i+1) && !st.query(i+1, n+1);

    }


    cout<<"\n";
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
4
1 3 2 1

1
6
6 3 4 3 2 1
*/
