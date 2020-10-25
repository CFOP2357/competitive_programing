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

#define MAX 60
#define MOD 1000000007

ull n, k;

vector<pii> adj[MAX][MAX];
vector<ull> cost[MAX][MAX];

int grid[MAX][MAX];
bool visited[MAX][MAX];

void solve(){
    cin>>n>>k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            for(int y=0; y<n; y++)
                for(int x=0; x<n; x++){
                    if(grid[i][j] == grid[y][x]-1){
                        adj[i][j].push_back({y, x});
                        cost[i][j].push_back(abs(i-y) + abs(j-x));
                    }
                }
        }


    priority_queue<pair<ull, pii>, vector< pair<ull, pii>>, greater<pair<ull, pii>>> nxt;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(grid[i][j]==1)
                nxt.push( {0, {i, j}} );

    while(nxt.size()){

        ull d = nxt.top().first;
        int i = nxt.top().second.first, j = nxt.top().second.second;
        nxt.pop();

        if(visited[i][j])
            continue;
        visited[i][j]=true;

        if(grid[i][j]==k){
            cout<<d<<"\n";
            return;
        }

        for(int u = 0; u<adj[i][j].size(); u++)
            nxt.push({cost[i][j][u]+d, adj[i][j][u] });

    }

    cout<<"-1\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

