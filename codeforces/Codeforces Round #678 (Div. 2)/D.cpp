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
ull n;

ull min_cost[MAX]; //lo que queda
ull max_cost[MAX]; //el maximo
ull cost[MAX]; //cost
ull amount[MAX]; //cost

ull dfs(int v){
    if(adj[v].size()==0){
        max_cost[v] = cost[v];
        amount[v] = 1;
        return cost[v];
    }

    for(int u : adj[v]){
        max_cost[v] = max(max_cost[v], dfs(u));
    }

    for(int u : adj[v]){
        if(cost[v]){
            ull d = min(cost[v], min_cost[u]);
            cost[v] -= d;
            min_cost[v] += min_cost[u]-d;

            if(max_cost[u] < max_cost[v]){
                ull d = min(cost[v], max_cost[u]);
                cost[v] -= d;
                min_cost[v] += max_cost[u]-d;
            }
        }
        else {
            ull d = min(cost[v], min_cost[u]);
            min_cost[v] += min_cost[u];
            if(max_cost[u] < max_cost[v])
                min_cost[v] += max_cost[u]-d;
        }
        amount[v] += amount[u];
    }

    if(cost[v]){
        ull d = min(cost[v], min_cost[v]);
        cost[v] -= d;
        min_cost[v] -= d;
    }

    if(cost[v]){
        ull d = cost[v]/amount[v];
        if(cost[v]%amount[v])
            min_cost[v] += amount[v] - cost[v]%amount[v];
        max_cost[v] = d;
    }


    return max_cost[v];

}

void solve(){

    cin>>n;
    for(int i=2; i<=n; i++){
        ull z; cin>>z;
        adj[z].push_back(i);
    }

    for(int i=1; i<=n; i++){
        cin>>cost[i];
    }

    cout<<dfs(1);



}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

