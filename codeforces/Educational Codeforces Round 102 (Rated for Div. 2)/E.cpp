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

#define MAX 200010
#define MOD 1000000007

vector<int> adj[MAX];
vector<ull> cost[MAX];
ull n, m;

vector<ull> minWithMax;
vector<ull> minWithMin;
vector<ull> minWithAll;
vector<ull> minWithNone;

void solve(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        ull u, v, w; cin>>u>>v>>w;

        adj[u].push_back(v);
        adj[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);

    }

    minWithMax.assign(n+1, LLONG_MAX);
    minWithMin.assign(n+1, LLONG_MAX);
    minWithNone.assign(n+1, LLONG_MAX);
    minWithAll.assign(n+1, LLONG_MAX);

    minWithAll[1] = minWithMin[1] = minWithMax[1] = INT_MAX;


    priority_queue<pii, vector<pii>, greater<pii>> nxt; //cost, v
    vector<bool> visited(n+1, false);

    //NONE
    nxt.push({0, 1});

    while(nxt.size()){

         ull cost = nxt.top().first;
         int v = nxt.top().second;
         nxt.pop();

         if(visited[v])
            continue;
         visited[v] = true;

         minWithNone[v] = cost;

         for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull edgeCost = ::cost[v][i];

            nxt.push({cost + edgeCost, u});
         }
    }

    //with max

    fill(all(visited), false);

    for(int v = 1; v<=n; v++){

        ull cost = minWithNone[v];

        for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull edgeCost = ::cost[v][i];
            nxt.push({cost, u});
        }

    }

    while(nxt.size()){

         ull cost = nxt.top().first;
         int v = nxt.top().second;
         nxt.pop();

         if(visited[v])
            continue;
         visited[v] = true;

         minWithMax[v] = cost;

         for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull edgeCost = ::cost[v][i];

            nxt.push({cost + edgeCost, u});
         }
    }

    //with min

    fill(all(visited), false);

    for(int v = 1; v<=n; v++){

        ull cost = minWithNone[v];

        for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull edgeCost = ::cost[v][i];
            nxt.push({cost + 2*edgeCost, u});
        }

    }

    while(nxt.size()){

         ull cost = nxt.top().first;
         int v = nxt.top().second;
         nxt.pop();

         if(visited[v])
            continue;
         visited[v] = true;

         minWithMin[v] = cost;

         for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull edgeCost = ::cost[v][i];

            nxt.push({cost + edgeCost, u});
         }
    }

    //with All

    fill(all(visited), false);

    for(int v = 1; v<=n; v++){

        for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull edgeCost = ::cost[v][i];
            nxt.push({minWithMax[v] + 2*edgeCost, u});
            nxt.push({minWithMin[v], u});

            if(v==1)
                nxt.push({edgeCost, u});
        }

    }

    while(nxt.size()){

         ull cost = nxt.top().first;
         int v = nxt.top().second;
         nxt.pop();

         if(visited[v])
            continue;
         visited[v] = true;

         minWithAll[v] = cost;

         for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull edgeCost = ::cost[v][i];

            nxt.push({cost + edgeCost, u});
         }
    }

    //print Ans
    for(int v = 2; v<=n; v++){
        cout<<minWithAll[v]<<" ";
    }
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

