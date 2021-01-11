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

#define MAX 100100
#define MOD 1000000007

vector<int> adj[MAX];
vector<pii> edge;

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v); adj[v].push_back(u);
        edge.push_back({u, v});
    }


    int toInsert = 1;
    vector<int> ans(n-1);
    for(int i=0; i<n-1; i++){
        if(min(adj[edge[i].first].size(), adj[edge[i].second].size()) == 1)
            ans[i] = toInsert++;
    }

    for(int a : ans){
        if(!a)
            a = toInsert++;
        cout<<a-1<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

