#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    long long x1, y1, z1;
    long long x2, y2, z2;
    cin>>x1>>y1>>z1;
    cin>>x2>>y2>>z2;


    long long ans = 0;

    if(z2<=x1){
        x1-=z2;
        z2 = 0;
    }
    else {
        z2-=x1;
        x1 = 0;
        if(z2<=z1){
            z1-=z2;
            z2 = 0;
        }
        else {
            z2-=z1;
            z1=0;
        }
    }

    ans = min(z1, y2)*(long long)2;
    ans -= z2*(long long)2;

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
