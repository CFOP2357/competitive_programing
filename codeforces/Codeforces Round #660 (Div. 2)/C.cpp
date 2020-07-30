#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, m;
int p[MAX]; //personas total
int h[MAX];
int toSolve[MAX];
bool visited[MAX];
int bad[MAX];
int good[MAX];

vector <int> road[MAX];

bool dfs(int i){
    if(visited[i])
        return true;
    visited[i]=true;

    //cout<<"v";
    if((p[i]-h[i])%2)
        return false;

    cout<<"#"<<i<<" "<<p[i]<<" "<<h[i]<<"\n";

    int realBad = (p[i]-h[i])/2;
    int realGood = p[i]-realBad;


    if(good[i] < realGood){
        if(bad[i]<realGood-good[i])
            return false;
        bad[i] -= realGood-good[i];
        good[i] += realGood-good[i];
    }
    //cout<<"#";

    if(bad[i]+good[i]!=p[i])
        return false;
    if(bad[i]!=realBad)
        return false;
    //cout<<"#";
    for(int v : road[i]){
        if(visited[v]) continue;
        p[v] += p[i];
        bad[v] += bad[i];
        good[v] += good[i];
        toSolve[v]--;
        if(!toSolve[v])
            if(!dfs(v))
                return false;
    }
    //cout<<"#";
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
        toSolve[i]=-1;
        visited[i]=false;
        bad[i]=good[i]=0;
    }

    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;
        road[x].push_back(y);
        road[y].push_back(x);
        toSolve[x]++;
        toSolve[y]++;
    }
    toSolve[1]++;

    for(int i=1; i<=n; i++){
        if(!toSolve[i]){
            if((p[i] - h[i])%2){
                cout<<"NO\n";
                return;
            }

            bad[i] = (p[i] - h[i])/2;
            good[i] = p[i] - bad[i];
            if(good[i]<0){
                cout<<"NO\n";
                return;
            }

            if(!dfs(i)){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    return;
}

int main(){
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
