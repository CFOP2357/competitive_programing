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


ull n, m, k;
vector<ull> adj[MAX];
bool visited[MAX];
bool jump[200];

void solve(){

    cin>>n>>m>>k;

    while(m--){
        ull u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    ull s, t; cin>>s>>t;

    queue<pii> nxt; //cost, v
    nxt.push({0, s});

    while(nxt.size()){
        ull cost = nxt.front().first, v = nxt.front().second;
        nxt.pop();
        if(v==t){
            cout<<cost<<"\n";
            return;
        }

        if(visited[v])
            continue;
        visited[v] = true;

        if(!jump[v%k]){
            jump[v%k] = true;
            for(ull u = 1; u<=n; u++)
                if(u%k == v%k)
                    nxt.push({cost+1, u});
        }

        for(ull u : adj[v])
            nxt.push({cost+1, u});

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

