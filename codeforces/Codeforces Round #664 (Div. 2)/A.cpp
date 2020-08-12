#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    int r, g, b, w;
    cin>>r>>g>>b>>w;

    int impar = r%2 + g%2 + b%2 + w%2;
    bool zero = !(r && g && b);

    if(!zero && impar !=2 ){
        cout<<"Yes\n";
    }
    else if(zero && impar<=1){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
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
