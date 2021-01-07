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

#define MAX 1000100
#define MOD 1000000007

ull n;

void solve(){

    cin>>n;

    vector<ull> degree(n+1, 0);
    priority_queue<pii> nxt; //w, i

    ull sum = 0;
    for(int i=1; i<=n; i++){
        ull z; cin>>z;
        nxt.push({z, i});
        sum+=z;
    }

    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;

        degree[u]++; degree[v]++;
    }

    cout<<sum<<" ";
    while(nxt.size()){
        ull v = nxt.top().second; ull w = nxt.top().first;

        if(degree[v] == 1){
            nxt.pop();
            continue;
        }

        sum += w;
        cout<<sum<<" ";

        degree[v]--;

    }

    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

