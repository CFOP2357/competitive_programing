#include <bits/stdc++.h>
using namespace std;

vector <int> w;

int posible(int s){
    //cout<<s<<": \n";
    int teams = 0;
    unordered_map<int, int> alone;
    alone.clear();
    for(int i=0; i<w.size(); i++){
        //cout<<w[i]<<" "<<s-w[i]<<"\n";
        if(alone.find(w[i])==alone.end())
            alone[w[i]]=0;
        if(alone.find(s-w[i])!=alone.end())
        {
            if(alone[s-w[i]]>0){
                teams++;
                alone[s-w[i]]--;
            }
            else {
                alone[w[i]]++;
            }
        }
        else alone[w[i]]++;
    }
    //cout<<"\n";
    return teams;
}

void solve(){
    int n;
    cin>>n;
    w.clear();
    for(int i=0; i<n; i++){
        int a; cin>>a;
        w.push_back(a);
    }

    int m=0;
    for(int i=0; i<=100; i++)
            m=max(m, posible(i));
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
