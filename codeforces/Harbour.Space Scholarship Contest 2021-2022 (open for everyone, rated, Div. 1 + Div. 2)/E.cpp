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

vector<ll> p;
ll n, m;
string s;

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

void solve(){
    p.clear();
    cin>>n>>m;
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        p.push_back(z-1);
    }

    vector<int> ok(n, 0);
    for(int i=0; i<n; i++)
        ok[(i-p[i]+n)%n]++;

    vector<int> ans;
    for(int i=0; i<n; i++){
        if(ok[i]+2*m>=n){
            UF uf(n);
            for(int j=0; j<n; j++)
                uf.join(j, p[(j+i)%n]);
            unordered_set<int> segment;
            for(int j=0; j<n; j++)
                segment.insert(uf.find(j));
            if(n-segment.size()<=m)
                ans.push_back(i);
        }
    }

    cout<<ans.size()<<" ";
    for(int k : ans)
        cout<<k<<" ";
    cout<<"\n";

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

