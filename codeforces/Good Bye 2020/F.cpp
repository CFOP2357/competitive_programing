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

#define MAX 500100
#define MOD 1000000007

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

vector<pii> adj;
ull n, m;

void solve(){

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int k, u, v; cin>>k;
        cin>>u;
        if(k>1) cin>>v;
        else v = 0;

        adj.push_back({u, v});
    }

    UF uf(m+2);

    vector<int> ans;
    for(int i=0; i<n; i++){
        auto s = adj[i];
        if(!uf.sameSet(s.first, s.second)){
            ans.push_back(i+1);
            uf.join(s.first, s.second);
        }
    }

    sort(all(ans));

    ull p = 1; for(int i=1; i<=ans.size(); i++) {
        p *= 2; p %= MOD;
    }

    cout<<p<<" "<<ans.size()<<"\n";
    for(int a : ans)
        cout<<a<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

