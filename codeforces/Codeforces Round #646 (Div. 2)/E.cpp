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

vector<ull> cost;
vector<bool> init;
vector<bool> goal;

ull n;

ull total = 0;

int dfs(int v, int p){
    cost[v] = min(cost[v], cost[p]);

    int ans = 0;

    if(init[v] != goal[v]){
        if(goal[v])
            ans++;
        else ans--;
    }

    for(int u : adj[v]){
        if(u==p) continue;

        int res = dfs(u, v);

        if( (res > 0 && ans < 0) || (res < 0 && ans > 0) )
            total += min(abs(ans), abs(res)) * cost[v] * 2;

        ans += res;
    }

    return ans;

}

void solve(){

    cin>>n;
    cost.push_back(LLONG_MAX); init.push_back(0); goal.push_back(0);
    for(int i=0; i<n; i++){
        int cost; cin>>cost;
        bool init, goal; cin>>init>>goal;
        ::cost.push_back(cost);
        ::goal.push_back(goal);
        ::init.push_back(init);
    }

    for(int i = 1; i<n; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(dfs(1, 0))
        cout<<"-1\n";
    else
        cout<<total<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

