#include <bits/stdc++.h>
using namespace std;

#define MAX 110
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;

char c[MAX][MAX];

void solve(){
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin>>c[i][j];
        }
    int ans = 0;
    for(int i=1; i<n; i++)
        ans += c[i][m]=='R';
    for(int i=1; i<m; i++)
        ans += c[n][i]=='D';

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

