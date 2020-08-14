#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector <ull> a;

void solve(){
    string s; cin>>s;
    a.clear();

    a.push_back(0);
    for(char c : s){
        if(c=='0'){
            if(a.back()>0)
                a.push_back(0);
        }
        else a.back()++;
    }
    if(a.back()==0)
        a.pop_back();

    sort(a.begin(), a.end());

    int ans = 0;
    while(a.size()){
        ans += a.back();
        a.pop_back();
        if(a.size()) a.pop_back();
    }

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
