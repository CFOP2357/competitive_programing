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

#include <assert.h>

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
typedef int64_t ll;
typedef uint64_t ull;
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

ll n, p;

void solve(){
    cin>>n>>p;

    UF uf(n+5);
    while(p--){
        int u, v;
        cin>>u>>v;
        uf.join(u, v);
    }

    set<int> uf_sets;
    for(int v = 1; v <= n; v++)
        uf_sets.insert(uf.find(v));

    vector<int> sizes;
    for(auto uf_set : uf_sets){
        sizes.push_back(uf.size(uf_set));
    }
    sort(all(sizes));

    vector<bool> dp(n+5, false);
    dp[0] = true;
    for(auto set_size : sizes){
        auto next_dp = dp;
        for(int i = 0; i < n; i++){
            if(dp[i] and i+set_size <= n)
                next_dp[i + set_size] = true;
        }
        dp = next_dp;
    }

    ll ans = 0;
    for(int m = 1; m <= n; m++){
        if(dp[m])
            ans++;
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

