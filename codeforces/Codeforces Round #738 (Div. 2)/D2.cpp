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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
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

vector<ll> a;
vector<ll> b;
ll n, m1, m2;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    cin>>m1>>m2;

    UF uf1(n+1);
    UF uf2(n+1);
    UF uf(n+1);

    vector<set<int>> not_possible(n+1, set<int>());

    for(int i = 0; i < m1; i++){
        int u, v; cin>>u>>v;
        uf1.join(u, v);
        not_possible[u].insert(v);
        not_possible[v].insert(u);
    }

    for(int i = 0; i < m2; i++){
        int u, v; cin>>u>>v;
        uf2.join(u, v);
        if(uf1.sameSet(u, v))
            uf.join(u, v);
    }

    vector<int> order;
    for(int u = 1; u <= n; u++)
        order.push_back(u);
    random_shuffle(all(order));

    vector<pii> ans;
    for(int i = 1; i < order.size(); i++){
        int u = order[i];
        int v = order[i-1];
        if(not uf1.sameSet(u, v) and not uf2.sameSet(u, v)){
            ans.push_back({u, v});
            uf1.join(u, v);
            uf2.join(u, v);
        }
    }

    cout<<ans.size()<<"\n";
    for(auto [u, v] : ans)
        cout<<u<<" "<<v<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

