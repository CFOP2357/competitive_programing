#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> b;

void solve(){
    a.clear();
    b.clear();
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
        b.push_back(z);
    }


    ull ans = 0;
    for(int i=0; i<n-1; i++){

        if(a[i]>a[i+1]){
            ans += b[i]- b[i+1];
            for(int j=i+1; j<n && a[j]>=a[j-1] && a[i]>a[j]; j++){
                a[j] = a[i];
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
}

