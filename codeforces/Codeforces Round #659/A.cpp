#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    char change = 'b';
    while(t--){
        int n; cin>>n;
        vector <int> el;
        for(int i=0; i<n; i++){
            int p; cin>>p;
            el.push_back(p);
        }

        string ans(60, 'a');
        cout<<ans<<"\n";

        for(int i : el){
            change++;
            if(change>'z') change = 'b';
            ans[i]=change;
            cout<<ans;
            cout<<"\n";
        }

    }

    return 0;
}
