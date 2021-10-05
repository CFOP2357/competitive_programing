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

vector<ll> a;
vector<ll> b;
ll n, m, k;
string s;

vector<vector<int>> adj;

ll xor_;
ll xor_components;

ll dfs(int u=1, int p=-1){
    ll current_xor = a[u];

    for(auto v : adj[u])
        if(v != p){
            current_xor ^= dfs(v, u);
        }

    if(current_xor == xor_){
        xor_components++;
        return 0;
    }
    return current_xor;
}

void solve(){
    a.clear(); b.clear(); xor_ = 0; xor_components = 0;
    cin>>n>>k;

    adj.assign(n+1, vector<int>());


    bool all_equal = true;
    a.push_back(0);
    for(int i = 1; i <= n; i++){
        ll z; cin>>z;
        a.push_back(z);

        if(i > 1 and z != a[i-1])
            all_equal = false;

        xor_ ^= z;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //cout<<xor_<<"\n";

    if(xor_ == 0)
        cout<<"YES\n";
    else if(k == n and all_equal)
        cout<<"YES\n";
    else if(k > 2 and dfs() == 0 and xor_components >= 3)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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

