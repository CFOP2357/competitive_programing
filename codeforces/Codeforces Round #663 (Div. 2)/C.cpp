#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

void solve(int i=0){
    if(i==a.size()){
        for(ull j : a)
            cout<<j<<" ";
        cout<<"\n";
        return;
    }
    for(int j=i; j<a.size();j++){
        swap(a[i], a[j]);
        solve(i+1);
        swap(a[i], a[j]);
    }
}

ull fact[MAX];
ull com[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    ull s = 0;
    com[1]=1;
    ull p=n-1;
    s+=1;
    for(int i=2; i<=n; i++){
        com[i] = com[i-1]*p;
        com[i]%=MOD;
        s+= com[i];
        s%=MOD;
        p--;
    }
    com[1 + n/2] = com[n/2]*p;
    com[1 + n/2] %= MOD;

    s*=2;
    s%=MOD;
    //cout<<s<<"\n";
    if(n%2){
        s+=com[1 + n/2];
        s%=MOD;
    }

    fact[0]=1;
    for(ull i=1; i<n+1; i++){
        fact[i] = fact[i-1]*i;
        fact[i] %= MOD;
    }
    fact[n] = fact[n-1]*n;
    fact[n] -= s;
    fact[n] %= MOD;

    cout<<fact[n]<<"\n";

    return 0;
}
