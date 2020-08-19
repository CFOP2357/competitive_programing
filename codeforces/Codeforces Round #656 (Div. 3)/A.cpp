#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    int x, y, z;
    cin>>x>>y>>z;
    int a = 0, b= 0, c = 0;

    a = min(x, y);
    b = min(x, z);
    c = min(y, z);

    if(max(a,b)==x && max(a, c)==y && max(b, c)==z)
        cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
    else cout<<"NO\n";

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
