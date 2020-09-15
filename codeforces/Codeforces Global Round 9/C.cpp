#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 1000100
#define MOD 1000000007

ull n;

void solve(){

    set <int, greater<int>> l;
    set <int> r;

    cin>>n;

    for(int i=1; i<=n; i++)
        r.insert(i);

    bool posible = true;
    for(int i=0; i<n; i++){
        int z; cin>>z;

        r.erase(z); l.insert(z);

        if(l.upper_bound(z)==l.end())
            if(r.upper_bound(z)==r.end())posible = false;

    }


    if(posible)
        cout<<"YES\n";
    else cout<<"NO\n";

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
