#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> impar;
vector <ull> par;

void solve(){
    /*a.clear();
    impar.clear();

    int n, k; cin>>n>>k;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    while(k--){
        int d = *max_element(a.begin(), a.end());
        for(int i=0; i<n; i++)
            a[i] = d - a[i];
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }*/

    a.clear();
    impar.clear();
    par.clear();
    ull n, k; cin>>n>>k;

    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    ull d = *max_element(a.begin(), a.end());
    for(int i=0; i<n; i++)
        impar.push_back(a[i] = d - a[i]);

    d = *max_element(a.begin(), a.end());
    for(int i=0; i<n; i++)
        par.push_back(a[i] = d - a[i]);

    if(k%((ull)2)){
        for(ull i : impar)
            cout<<i<<" ";
    }
    else {
        for(ull i : par)
            cout<<i<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
