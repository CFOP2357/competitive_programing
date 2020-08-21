#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    int n, k;
    cin>>n>>k;
    if(n<k)
        cout<<k-n<<"\n";
    else {
        if(n%2 != k%2){
            cout<<1<<"\n";
        }
        else cout<<0<<"\n";
    }
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
