#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin>>n>>m>>t;

    vector <pair<int, int>> p; // last, first

    int x;
    for(int i = 0; i<t; i++){
        cin>>x;
        cin>>x;
        p.push_back( {x+150, x-150} );
    }
    sort(p.begin(), p.end(), less<pair<int, int>>());

    int ans = 1;
    int last = p[0].first;
    for(pair <int, int> i : p){
        if(i.second > last){
            last = i.first;
            ans++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}

