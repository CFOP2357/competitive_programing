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

typedef int ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 100100
#define MOD 1000000007

vector<vi> adj;
ull n;

bool odd, even;

void dfs(int v, int p = -1, int d = 0){

    for(int u : adj[v]){
       if(u==p)
            continue;
        dfs(u, v, d+1);
    }

    if(adj[v].size()==1){
        if(d%2)
            odd = true;
        else even = true;
    }

}

bool selected[MAX];
void solve(){
    cin>>n;
    adj.assign(n+5, vi());
    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int r;
    for(int i=1; i<=n; i++)
        if(adj[i].size()>1){
            r=i;
            break;
        }

    //cout<<r<<"#\n";
    dfs(r);

    if(odd != even)
        cout<<"1 ";
    else cout<<"3 ";

    ull ans = n-1;
    for(int i=1; i<=n; i++){
        if(adj[i].size()==1){
            if(selected[adj[i][0]])
                ans--;
            selected[adj[i][0]]=true;
        }
    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

