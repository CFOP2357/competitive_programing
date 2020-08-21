#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
#define MOD 1000000007

typedef long long ull;

vector<int> g[MAX];
deque<long long> p;
bool visited[MAX];
int pendient[MAX];
int s[MAX];
ull n;
vector<ull>edge;

void dfs(int v){
    if(visited[v])
        return;
    visited[v] = true;

    for(int u : g[v]){
        if(!visited[u]){
            edge.push_back( s[v]*(n-s[v]));
            if(pendient[u]){
                s[u] += s[v];
                pendient[u]--;
                if(!pendient[u]){
                    dfs(u);
                }
            }
        }
    }
}

void solve(){
    p.clear();
    edge.clear();
    cin>>n;
    for(int i=0; i<=n; i++){
            g[i].clear();
            visited[i]=false;
            s[i] = 1;
    }

    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int m; cin>>m;
    for(int i = 0; i<m; i++){
            int z; cin>>z;
            p.push_back(z);
    }

    for(int i = 1; i<=n ;i++){
        pendient[i]=g[i].size()-1;
    }

    for(int i = 1; i<=n ;i++){
        if(!visited[i] && !pendient[i]){
            dfs(i);
        }
    }

    ull ans = 0;
    sort(edge.begin(), edge.end(), greater<ull>());
    sort(p.begin(), p.end(), greater<ull>());
    while(p.size()>edge.size()){
        p[1]*=p[0];
        p[1] %= MOD;
        p.pop_front();
    }
    for(int i = 0; i<p.size() && i<edge.size(); i++){
        //cout<<p[i]<<" "<<edge[i]<<" #\n";
        edge[i]%=MOD;
        ans += (edge[i]*p[i])%MOD;
        ans %= MOD;
    }
    if(edge.size()>p.size()){
        for(int i = p.size(); i<edge.size(); i++){
            ans += edge[i]%MOD;
            ans %= MOD;
        }
        ans%=MOD;
    }

    cout<<ans<<"\n";

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
