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

ll n;

vector<bool> visited;
vector<int> T;
int current_T = 1;
vector<ll> node_ans;
unordered_map<int, vector<int>> adj;
vector<int> order;

ll dfs(int u){
    if(visited[u])
        return node_ans[u];
    visited[u] = true;

    ll ans = 0;

    for(auto v : adj[u])
        ans = max(ans, dfs(v) + (int)(v < u));

    node_ans[u] = ans;
    return ans;
}

void top_sort(int u){
    if(visited[u])
        return;
    visited[u] = true;

    for(auto v : adj[u])
        top_sort(v);

    order.push_back(u);
    T[u] = current_T++;
}

void solve(){
    cin>>n;

    ll ans = 0;
    adj.clear();
    order.clear();
    T.assign(n+1, 0);
    current_T = 0;
    visited.assign(n+1, false);
    node_ans.assign(n+1, 0);

    for(int v = 1; v <= n; v++){
        ll k; cin>>k;

        while(k--){
            ll u; cin>>u;
            adj[u].push_back(v);
        }
    }

    for(int u = 1; u <= n; u++){
        top_sort(u);
    }

    for(int u = 1; u <= n; u++)
        for(auto v : adj[u])
            if(T[u] < T[v]){
                cout<<"-1\n";
                return;
            }

    visited.assign(n+1, false);

    for(auto u : order){
        //cout<<dfs(u)<<" ";
        ans = max(dfs(u), ans);
    }
    //cout<<"\n";

    cout<<ans+1<<"\n";

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

/*
1
5
1 2
1 3
1 4
1 5
0
*/
