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


#define MAX 200100
#define MOD 1000000007


ll n;

vector<int> adj[MAX];

struct NodeData{
    bool is_leaf = false;
    ll buds = 0;
    ll leafs = 0;
};

NodeData get_data(int v, int p=-1){
    if(v != 1 and adj[v].size() == 1){ //is_leaf
        return {true, 0, 1};
    }

    //cout<<v<<"%\n";

    bool is_bud = false;
    ll buds = 0;
    ll leafs = 0;
    bool is_leaf = false;
    for(auto u : adj[v]){
        if(u == p)
            continue;

        auto data = get_data(u, v);

        if(data.is_leaf)
            is_bud = true;
        buds += data.buds;
        leafs += data.leafs;
    }

    if(v != 1 and is_bud)
        buds++;

    if(v != 1 and !is_bud){
        leafs++;
        is_leaf = true;
    }

    if(v == 1 and !is_bud and buds){
        buds--;
    }

    return {is_leaf, buds, leafs};
}

void solve(){
    cin>>n;

    for(int i = 1; i <= n; i++)
        adj[i].clear();

    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto data = get_data(1);

    //cout<<data.leafs<<" "<<data.buds<<"\n";

    ll ans = data.leafs - data.buds;
    ans = max((ll)1, ans);

    cout<<ans<<"\n";

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
7
1 2
1 3
1 4
2 5
2 6
4 7

1
2
1 2

1
9
1 2
2 3
2 4
4 5
4 6
6 7
7 8
8 9

1
3
1 2
2 3

1
4
1 2
2 3
2 4

1
15
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
*/
