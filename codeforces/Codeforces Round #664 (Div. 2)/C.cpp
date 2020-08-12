#include <bits/stdc++.h>
using namespace std;

#define MAX 1100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

bool exist[MAX];

bool posible(int ans){
    for(int i : a){
        bool p = false;
        for(int j : b){
            if( ((i&j)&(~ans)) == 0)
                p=true;
        }
        if(!p) return false;
    }
    return true;
}

void solve(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<m; i++){
        int z; cin>>z;
        b.push_back(z);
    }

    sort(a.begin(), a.end(), greater<int>());

    int o = 0;
    for(int ans = 0; ans<600; ans++)
        if(posible(ans)){
            cout<<ans<<"\n";
            return;
        }

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
