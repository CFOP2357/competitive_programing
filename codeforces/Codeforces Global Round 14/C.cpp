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

#define MAX 1000100
#define MOD 1000000007

vector<pii> h;
vector<ull> b;
ull n, m, x;
string s;

void solve(){
    h.clear();
    cin>>n>>m>>x;
    vector<int> ans(n, 0);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        h.push_back({z, i});
    }
    sort(all(h), greater<pii>());

    multiset<pii> towers;
    for(int i=1; i<=m; i++)
        towers.insert({0, i});

    for(auto [height, id] : h){
        ull current_height = towers.begin()->first;
        ull current_tower = towers.begin()->second;
        towers.erase(towers.begin());

        ans[id] = current_tower;
        towers.insert({height + current_height, current_tower});
    }

    if(abs(towers.begin()->first - towers.rbegin()->first) > x)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(int tower_id : ans)
            cout<<tower_id<<" ";
        cout<<"\n";
    }

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

