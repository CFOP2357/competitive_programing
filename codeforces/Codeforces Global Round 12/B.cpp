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

#define MAX 200
#define MOD 1000000007

vector<pii> a;

ull n, k;

ull d(int i, int j){
    return abs(a[i].first-a[j].first) + abs(a[i].second-a[j].second);
}

void solve(){
    a.clear();

    cin>>n>>k; a.push_back({0, 0});
    for(int i=1; i<=n; i++){
        ull x, y; cin>>x>>y;
        a.push_back({x, y});
    }

    for(int i=1; i<=n; i++){
        ull sz = 0;
        for(int j=1; j<=n; j++){
            if(d(i, j)>k)
                continue;
            sz++;
        }
        if(sz==n){
            cout<<1<<"\n";
            return;
        }
    }
    cout<<"-1\n";
    return;


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

