#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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

#define MAX 1005
#define MOD 1000000007

vector<ull> piles;
ull n, x;

vector<int> adj[MAX];

int dfs(int v, int p){

    int ans = 1;
    for(int u : adj[v]){
        if(u==p) continue;
        ans += dfs(u, v);
    }

    return ans;
}

void solve(){
    piles.clear();
    fill(adj, adj+MAX, vector<int>());

    cin>>n>>x;
    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(int u : adj[x])
        piles.push_back(dfs(u, x));

    if(piles.size() <= 1){
        cout<<"Ayush\n";
        return;
    }

    int sum = 0;
    for(int k : piles) sum+=k;
    sum--;

    if(sum%2)
        cout<<"Ashish\n";
    else cout<<"Ayush\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

