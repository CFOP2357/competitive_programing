#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin>>n;
    string a, b; cin>>a>>b;

    bitset<21> dp[21];

    for(int i=0; i<n; i++){
        if(a[i]>b[i]){
            cout<<-1<<"\n";
            return;
        }
        if(a[i]<b[i]){
            dp[a[i]-'a'][b[i]-'a']=true; //quiero llegar a b[i]
        }
    }

    int ans = 0;
    for(int i=0; i<21; i++){
        for(int j=i+1; j<21; j++){
            if(dp[i][j]){
                ans++;
                dp[j] |= dp[i];
                break;
            }
        }
    }

    cout<<ans<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
