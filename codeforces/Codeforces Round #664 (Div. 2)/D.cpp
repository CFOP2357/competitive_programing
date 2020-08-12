#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

long long dp[MAX];

void solve(){
    int n, d, m;
    cin>>n>>d>>m;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }
    sort(a.begin(), a.end());
    long long ans =0;
    int notAngry=-1;
    for(int i=0; i<a.begin(); i++){
        if(a[i]<=m)
            notAngry = i;
    }

    for(int i=0; i<n; i++){
        if(a[i]>m){
            int next = min(i+d, n);
            dp[next] = max(dp[next], dp[i]+a[i]);
            ans = max(dp[next], ans);
        }
        else {
            int next = i+1;
            dp[next] = max(dp[next], dp[i]+a[i]);
            ans = max(dp[next], ans);
        }
    }
    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
