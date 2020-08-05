#include <bits/stdc++.h>
using namespace std;

vector <int> a;

void solve(){
    int n;
    cin>>n;
    a.clear();
    for(int i=0; i<n; i++){
        int b; cin>>b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    for(int i=1; i<n; i++)
        if(a[i]-a[i-1]>1){
            cout<<"NO\n";
            return;
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

}
