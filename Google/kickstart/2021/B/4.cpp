#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>s(ans, route[v].A);
    getAns(route[v].nxt);
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>q;
    for(int i=0; i<=n; i++){
        adj[i].clear();
        L[i].clear();
        A[i].clear();
    }

    for(int i=1; i<n; i++){
        ull x, y, l, a; cin>>x>>y>>l>>a;
        adj[x].push_back(y);
        L[x].push_back(l);
        A[x].push_back(a);

        adj[y].push_back(x);
        L[y].push_back(l);
        A[y].push_back(a);
    }

    route.assign(n+5, {0, 0, 0});
    defRoute();

    while(q--){
        cin>>c>>w; ans = 0;
        getAns(c);
        cout<<ans<<" ";
    }
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}
/*
1
3 2
1 2 2 10
3 2 3 5
3 2
3 3
*/
