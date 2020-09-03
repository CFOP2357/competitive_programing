#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> r(35, 0);
    for(int i=0; i<n; i++){
        int z; cin>>z;

        for(int i=0; z; i++, z/=2)
            r[i]+=z%2;
    }

    for(int i=34; i>=0; i--){
        if(r[i]){
          if(r[i]%2){
           if(r[i]%4 == 1){
                cout<<"WIN\n";
           }
           if(r[i]%4 == 3){
                if((n-r[i])%2)
                    cout<<"WIN\n";
                else cout<<"LOSE\n";
           }
           return;
          }
        }
    }
    cout<<"DRAW\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

