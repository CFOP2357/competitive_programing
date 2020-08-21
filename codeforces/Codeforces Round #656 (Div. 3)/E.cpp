#include <bits/stdc++.h>
using namespace std;

#define MAX 200010
#define MOD 1000000007

typedef long long ull;

vector<int> g[MAX];
vector<pair<int, int>> edge;
int pos[MAX];
bool hasC;

void dfs(int v, int &order){
    if(pos[v])
        return;
    pos[v]=-1;
    for(int u : g[v]){
        if(pos[u]==-1)
            hasC=true;
        dfs(u, order);
    }
    order++;
    pos[v] = order;
}

void solve(){
    int n, m; cin>>n>>m;
    for(int i=1; i<=n; i++){
            pos[i]=0;
            g[i].clear();
    }

    edge.clear();
    for(int i=0; i<m; i++){
        int t, u, v;
        cin>>t>>u>>v;
        if(t){
            g[u].push_back(v);
        }
        edge.push_back({u, v});
    }

    hasC = false;
    int order = 0;
    for(int i=1; i<=n; i++){
        if(!pos[i]){
            dfs(i, order);
        }
    }

    if(hasC){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        for(auto p : edge){
            if(pos[p.first]>pos[p.second])
                cout<<p.first<<" "<<p.second<<"\n";
            else
                cout<<p.second<<" "<<p.first<<"\n";
        }
    }

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
