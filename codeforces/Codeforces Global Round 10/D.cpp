#include <bits/stdc++.h>
using namespace std;

#define MAX 500100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

ull dp[MAX];

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    s+=s;
    ull ans;

    for(int i=0; i<n; i++) dp[i] = INT_MAX;

    dp[0] = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='R'){
            if(s[i+1]=='L'){
                dp[i+2] = min(dp[i+2], dp[i]);
                dp[i+1] = min(dp[i+1], dp[i]+1);
            }
            else {
                dp[i+2] = min(dp[i+2], dp[i]+1);
                dp[i+1] = min(dp[i+1], dp[i]+1);
            }
        }
        else {
            if(s[i+1]=='R'){
                dp[i+2] = min(dp[i+2], dp[i]+2);
                dp[i+1] = min(dp[i+1], dp[i]+1);
            }
            else {
                dp[i+2] = min(dp[i+2], dp[i]+1);
                dp[i+1] = min(dp[i+1], dp[i]+1);
            }
        }
    }

    ans = min(dp[n], dp[n+1]);


    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
