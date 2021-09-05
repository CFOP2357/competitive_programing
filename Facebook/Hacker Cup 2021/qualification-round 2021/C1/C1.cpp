//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

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

ofstream fout ("out.txt");
ifstream fin ("in.txt");


#define MAX 1000100
#define MOD 1000000007

ll n, m;
string s;

vector<ll> cost;
vector<vector<int>> adj;
vector<ll> subtree_max_cost;

ll get_max_cost(int node, int parent){
    ll max_cost = 0;

    for(auto child : adj[node]){
        if(child == parent)
            continue;
        max_cost = max(get_max_cost(child, node), max_cost);
    }

    max_cost += cost[node];
    return max_cost;
}

void solve(){
    cost.clear();
    subtree_max_cost.clear();

    fin>>n;

    cost.push_back(0);
    for(int i = 1; i <= n; i++){
        ll z; fin>>z;
        cost.push_back(z);
    }

    adj.assign(n+1, vector<int>());
    for(int i = 1; i < n; i++){
        int a, b;
        fin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(auto child : adj[1]){
        subtree_max_cost.push_back(get_max_cost(child, 1));
    }

    sort(all(subtree_max_cost), greater<ll>());

    ll ans = cost[1];
    if(subtree_max_cost.size() > 0)
        ans += subtree_max_cost[0];
    if(subtree_max_cost.size() > 1)
        ans += subtree_max_cost[1];

    fout<<ans<<"\n";
}


int main(){
    //srand (time(NULL));

    ull T = 1;
    int t=1; fin>>t;
    while(t--){
        fout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

