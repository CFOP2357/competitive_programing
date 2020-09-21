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

#define MAX 200100
#define MOD 1000000007

vector<int> adj[MAX];
vector<int> p[MAX];
ull n, m;

vector<int> ans;
vector<int> order;

bool visited[MAX];
int dp[MAX];

void tSort(int v){
    if(visited[v]) return;
    visited[v] = true;

    for(int u : adj[v])
        tSort(u);
    order.push_back(v);
}

void solve(){
    ans.clear(); order.clear();
    cin>>n>>m;
    fill(adj, adj+n+5, vector<int>());
    fill(p, p+n+5, vector<int>());
    fill(visited, visited+n+5, false);
    fill(dp, dp+n+5, 0);

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        p[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        tSort(i);

    reverse(all(order));
    for(int v : order){
        //cout<<v<<" "<<dp[v]<<"\n";
        if(dp[v] == 2){
            dp[v] = -1;
            ans.push_back(v);
            continue;
        }

        for(int u : adj[v])
            dp[u] = max(dp[v]+1, dp[u]);

    }

    cout<<ans.size()<<"\n";
    for(int a : ans)
        cout<<a<<" ";
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
5 7
2 3
1 4
2 4
3 4
3 5
1 3
4 5

1
3 3
1 2
2 3
1 3

1
5 7
4 5
2 5
1 2
1 3
2 4
3 4
3 5
*/
