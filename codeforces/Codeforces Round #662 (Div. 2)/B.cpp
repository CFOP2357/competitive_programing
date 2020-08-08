#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int a[MAX];
int n;
int cuatro;
int pares;

void solve(){
    char op; cin>>op;
    int x;cin>>x;

    if(op=='+'){
        a[x]++;
        if(a[x]%2==0)
            pares++;
        if(a[x]%4==0)
            cuatro++;
    }
    else {
        if(a[x]%4==0){
            cuatro--;
            pares--;
        }
        else if(a[x]%2==0)
            pares--;
        a[x]--;
    }

    //cout<<cuatro<<" "<<pares<<" ";

    if(cuatro>=1 && pares>3){
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        int b; cin>>b;
        a[b]++;
        if(a[b]%2==0)
            pares++;
        if(a[b]%4==0)
            cuatro++;
    }
    int q; cin>>q;
    while(q--)
        solve();

}
