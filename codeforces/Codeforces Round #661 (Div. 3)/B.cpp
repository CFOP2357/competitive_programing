#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> b;

void solve(){
    a.clear();
    b.clear();
    int n;
    cin>>n;
    a.clear();
    for(int i=0; i<n; i++){
        int c; cin>>c;
        a.push_back(c);
    }
    for(int i=0; i<n; i++){
        int c; cin>>c;
        b.push_back(c);
    }
    int mA = *min_element(a.begin(), a.end());
    int mB = *min_element(b.begin(), b.end());
    long long s=0;

    for(int i=0; i<n; i++){
        int difA = a[i]-mA;
        int difB = b[i]-mB;
        if(difA && difB){
            int d = min(difA, difB);
            s+= d;
            difA-=d;
            difB-=d;
        }
        s+=difA;
        s+=difB;
    }
    cout<<s<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }

}

