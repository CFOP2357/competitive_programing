#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 200100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, q;
string s;

vector<ull> adj[MAX];
vector<ull> L[MAX];
vector<ull> A[MAX];

struct Route{
    ull nxt;
    ull L;
    ull A;
};

vector<Route> route;

void defRoute(int v=1, int p=-1){

    for(int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];
        if(u!=p){
            route[u] = {v, L[v][i], A[v][i]};
        }
    }

    for(int u : adj[v])
        if(u!=p)
            defRoute(u, v);

}

ull c, w, ans;

void getAns(int v){
    if(v==1)
        return;
    if(route[v].L <= w)
        ans = __gcd(ans, route[v].A);
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
