#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> b;


void solve(){
    int n;cin>>n;
    a.clear();
    b.clear();
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }
    sort(a.begin(), a.end());

    int last = a[0];
    b.push_back(1);
    for(int i : a){
        //cout<<b.back()<<"\n";
        if(i==last){
            b.back()++;
        }
        else {
            b.push_back(1);
            last = i;
        }
    }
    b[0]--;

    sort(b.begin(), b.end(), greater<int>());
    int m = INT_MAX;
    for(int k : b){
        //cout<<k<<" ";
        if(k==1)
            continue;
        m = min(m, (n-k)/(k-1));
        n--;
    }

    cout<<m<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }

}
