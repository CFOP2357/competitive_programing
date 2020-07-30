#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, m;
int p[MAX]; //personas
int total[MAX];
int h[MAX];
bool visited[MAX];
int bad[MAX];
int good[MAX];

vector <int> road[MAX];

bool dfs(int i){
    if(visited[i])
        return true;
    visited[i]=true;

    int sum = 0;
    int sumGood = 0;
    for(int v : road[i]){
        if(!dfs(v))
            return false;
        sum+= total[v];
        sumGood += good[v];
    }
    sum+=p[i];

    if((h[i]+sum)%2)
        return false;

    good[i] = (h[i]+sum)/2;
    bad[i] = sum - good[i];

    //cout<<"#"<<i<<" "<<good[i]<<" "<<bad[i]<<"\n";

    if(bad[i]<0)
        return false;

    if(good[i]<sumGood)
        return false;

    total[i] = sum;
    return true;
}

void solve(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>p[i];
    for(int i=1; i<=n; i++)
        cin>>h[i];
    for(int i=1; i<=n; i++){
        road[i].clear();
        visited[i]=false;
        bad[i]=good[i]=0;
        total[i] = 0;
    }

    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;
        road[x].push_back(y);
        road[y].push_back(x);
    }

    if(dfs(1))
        cout<<"YES\n";
    else cout<<"NO\n";

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
