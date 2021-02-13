#include <iostream>

using namespace std;

typedef long long ull;
ull x, y;

void solve(){

    cin>>x>>y;
    y = min(y, x-1);

    ull ans = 0;
    for(ull k = 1; k<=y && (k+1)*k+k <= x; k++){
        ull d = min((x-k)/(k), y);
        ans += d-k;
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

