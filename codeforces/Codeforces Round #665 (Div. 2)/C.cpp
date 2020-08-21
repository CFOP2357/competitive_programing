#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;

void solve(){
    a.clear(); b.clear();
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
        b.push_back(z);
    }

    sort(b.begin(), b.end());
    ull m = b[0];

    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            if(a[i]%m!=0 || b[i]%m!=0){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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

/*
4 3 6 6 2 9
2 3 4 6 6 9

*/
