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

vector<ull> adj[MAX];
vector<ull> inv[MAX];

vector<ull> p;
ull n, m, k;

ull d[MAX];

void bfs(){

    queue<pii> nxt; //v, d

    nxt.push({p.back(), 1});

    while(nxt.size()){
        int v = nxt.front().first;
        ull cost = nxt.front().second;
        nxt.pop();

        //cout<<v<<" "<<cost<<"#\n";

        if(d[v])
            continue;
        d[v] = cost;

        for(int u : inv[v])
            nxt.push({u, cost+1});

    }

}

void solve(){

    cin>>n>>m;
    while(m--){
        ull v, u;
        cin>>v>>u;

        adj[v].push_back(u);
        inv[u].push_back(v);

    }

    cin>>k;
    for(int i=0; i<k; i++){
        ull z; cin>>z;
        p.push_back(z);
    }

    bfs();
    /*for(int v = 1; v<=n; v++)
        cout<<d[v]<<" ";
    cout<<"\n";*/

    ull ansMax = 0, ansMin = 0;
    for(int i = 0; i<k-1; i++){

        if(d[p[i+1]] != d[p[i]]-1)
            ansMin++;

        bool anotherJourney = false;
        for(int u : adj[p[i]]){
            if(u==p[i+1])
                continue;

            if(d[u]==d[p[i]]-1)
                anotherJourney=true;

        }

        ansMax += anotherJourney;

    }

    cout<<ansMin<<" "<<ansMax<<"\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

