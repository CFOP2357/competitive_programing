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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    ull s = 1;
    for(int i=1; i<n; i++){
        s*=2;
        s%=MOD;
    }

    fact[0]=1;
    for(ull i=1; i<=n; i++){
        fact[i] = fact[i-1]*i;
        fact[i] %= MOD;
    }

    if(fact[n]-s < 0)
        cout<<(fact[n]+MOD-s)%MOD;
    else
        cout<<fact[n]-s;
    return 0;
}
