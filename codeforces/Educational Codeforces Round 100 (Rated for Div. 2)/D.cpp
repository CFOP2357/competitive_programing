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

/////////////////////////////////////
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
/////////////////////////////////////

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear();

    cin>>n;

    Tree st(2*n+5, 0);
    for(int i=0; i<=2*n; i++){
        st.update(i, 1);
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        st.update(z, 0);
    }
    st.update(0, 0);

    /*cout<<st.query(0, 4)<<" ";
    for(int i=0; i<=2*n; i++)
        cout<<st.query(i, i+1)<<" ";
    cout<<"#\n";*/

    int last, first;

    ull sz = n;
    for(first = 0; first<n; first++){
        sz = min(sz, st.query(a[first], 2*n+1));
        if(!sz)
            break;
        sz--;
    }
    first--;

    sz = n;
    for(last = n-1; last>=0; last--){
        sz = min(sz, st.query(0, a[last]));
        //cout<<sz<<" ";
        if(!sz)
            break;
        sz--;
    } //cout<<"\n";


    //cout<<first<<" "<<last<<"\n";
    cout<<first-last+1<<"\n";

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
1 4 5 9 10

1
2
3 4
*/
