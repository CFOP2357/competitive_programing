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
typedef ull ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct Tree {
	typedef ull T;
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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, p;
string s;

int bsLeft(Tree &st, const int val, int l, int r){ //(l, r]

    if(l+1 >= r)
        return r;

    int m = (l+r)/2;

    if(st.query(m, r+1) != val)
        return bsLeft(st, val,m, r);
    return bsLeft(st, val, l, m);

}

int bsRight(Tree &st, const int val, int l, int r){ //[l, r)

    if(l+1 >= r)
        return l;

    int m = (l+r)/2;

    if(st.query(l, m+1) != val)
        return bsRight(st, val,l, m);
    return bsRight(st, val, m, r);

}

void solve(){
    a.clear(); b.clear();
    cin>>n>>p;

    priority_queue<pii, vector<pii>, greater<pii>> nxt; //val, pos

    Tree st(n+1);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        st.update(i, z);
        nxt.push({z, i});
    }

    ull ans = 0;

    UF uf(n);
    while(nxt.size() && nxt.top().first < p){

        int i = nxt.top().second;
        nxt.pop();

        cout<<i<<"%\n";
        int l = bsLeft(st, a[i], -1, i);
        for(int j = l; j<i && !uf.sameSet(j, i); j++){
            ans += a[i];
            uf.join(j, i);
        }
        for(int j = i-1; j>=l && !uf.sameSet(j, i); j--){
            ans += a[i];
            uf.join(j, i);
        }

        int r = bsRight(st, a[i], i, n);
        for(int j = r; j>i && !uf.sameSet(i, j); j--){
            ans += a[i];
            uf.join(i, j);
        }
        for(int j = i+1; j<=r && !uf.sameSet(i, j); j++){
            ans += a[i];
            uf.join(i, j);
        }

    }

    //cout<<st.query(1, 3)<<"#\n";

    set<int> component;
    for(int i=0; i<n; i++)
        component.insert(uf.find(i));

    ans += ((ull)(component.size()-1))*p;

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

/*
1
4 5
5 2 4 9

1
8 8
5 3 3 6 1 100 9 15
*/
