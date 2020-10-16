#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define all(a) a.begin(), a.end()

typedef int32_t ull;

#define MAX 1000002
#define MOD 1000000007

vector<ull> a;
vector<ull> b;

ull n, q;

bool posible(int x){
    int sz = 0;

    for(int k : a)
        if(k<=x)
            sz++;

    for(int k : b){
        if(k>0 && k<=x)
            sz++;
        if(k<0 && abs(k)<=sz)
            sz--;
    }


    return sz>0;
}

void solve(){
    a.clear(); b.clear();

    cin>>n>>q;

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }


    for(int i=0; i<q; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    if(!posible(MAX)){
        cout<<"0\n";
        return;
    }

    int l =0, r = MAX;
    while(l+1<r){
        int m = (l+r)/2;
        if(posible(m))
            r = m;
        else
            l = m;
    }

    cout<<r<<"\n";



}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

