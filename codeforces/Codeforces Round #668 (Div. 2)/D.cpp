#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define MAX 100100
#define MOD 1000000007

typedef long long ull;

int n, a, b, da, db;
int P;
vector<int> adj[MAX];

bool dfs(int v, int d, int p = -1){
    if(v==b && d>=0)
        return true;

    if(v==b)
      P = p;

    for(int u : adj[v]) if(u!=p) {
        if(dfs(u, d-1, v))
            return true;
    }

    return false;
}

int D(0), vD(b);
void  dfs2(int v, int p = -1, int d = 0){

    if(d>D) {
       D = d;
       vD = v;
    }

    for(int u : adj[v]) if(u!=p)
        dfs2(u, v, d+1);

}

void solve(){

    cin>>n>>a>>b>>da>>db;
    D = 0,vD = b, P=-1;

    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(da>=db || dfs(a, da)){
        cout<<"Alice\n";
        return;
    }

    dfs2(b);
    D = 0;
    dfs2(vD);

    //cout<<D<<" ";

    if(min(D+1, db+1) > da*2+1)
        cout<<"Bob\n";
    else cout<<"Alice\n";

}

/*
1
11 8 11 3 5
1 2
11 9
4 9
6 5
2 10
3 2
5 9
8 3
7 4
7 10

1
11 8 11 3 3
1 2
11 9
4 9
6 5
2 10
3 2
5 9
8 3
7 4
7 10
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
        solve();

    return 0;
}

