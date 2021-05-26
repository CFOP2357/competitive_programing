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

#define MAX 200010
#define MOD 1000000007

vector<ull> l;
vector<ull> r;
ull n, m;
string s;

vector<int> adj[MAX];
ull max_l[MAX];
ull max_r[MAX];

void dfs(int current = 1, int parent =-1){
    for(auto child : adj[current]){
        if(child == parent)
            continue;
        dfs(child, current);
        max_l[current] += max(
            max_l[child] + abs(l[current] - l[child]),
            max_r[child] + abs(l[current] - r[child])
        );
        max_r[current] += max(
            max_l[child] + abs(r[current] - l[child]),
            max_r[child] + abs(r[current] - r[child])
        );
    }
}

void solve(){
    l.clear(); r.clear();
    cin>>n;

    l.push_back(0); r.push_back(0);
    for(int i=1; i<=n; i++){
        ull R, L; cin>>L>>R;
        l.push_back(L);
        r.push_back(R);
        adj[i].clear();
        max_l[i] = max_r[i] = 0;
    }

    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    cout<<max(max_l[1], max_r[1])<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

