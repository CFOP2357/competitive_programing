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

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 300100
#define MOD 1000000007

ull n;

vector<int> adj[MAX];
int sz[MAX];
int P[MAX];
int c1,c2;
int m;

int dfs(int v, int p=-1){
    int ans = 1;

    for(int u : adj[v]){
        if(u!=p){
            ans += dfs(u, v);
        }
    }

    sz[v] = ans;
    return ans;
}

void dfs2(int v, int p=-1){

    int comp = INT_MIN;

    if(p>0){
        comp = sz[1]-sz[v];
    }

    P[v] = p;

    for(int u : adj[v]){
        if(u!=p){
            //cout<<u<<" ";
            dfs2(u, v);
            if(comp<sz[u]){
                comp = sz[u];
            }
        }
    }

    //cout<<v<<" "<<comp<<"#\n";

    if(comp<m){
        m = comp;
        c1 = v;
        c2 = 0;
    }
    else if(comp == m){
        c2 = v;
    }

}

int l = -1;
bool dfs3(int v, int p=-1){
    //cout<<v<<"$\n";
    if(adj[v].size()==1 && v!=c2){
        l = v;
    }

    for(int u : adj[v]){
        if(u!=p){
            if(dfs3(u, v))
                return true;
        }
    }

    return false;
}

void solve(){

    cin>>n;

    fill(sz, sz+n+1, 0);
    for(int i=1;i<=n; i++)
        adj[i].clear();

    for(int i=1;i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    c1=0, c2=0, m=INT_MAX;

    dfs(1);

    dfs2(1);

    //cout<<c1<<" "<<c2<<"#\n";

    if(c1 && !c2){
        for(int i=1; i<=n; i++){
            for(int u : adj[i]){
                cout<<i<<" "<<u<<"\n";
                cout<<i<<" "<<u<<"\n";
                return;
            }
        }
    }

    dfs3(c1, P[c1]);
    //cout<<l<<"\n";return;

    cout<<adj[l][0]<<" "<<l<<"\n";
    cout<<c2<<" "<<l<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

