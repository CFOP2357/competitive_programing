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

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

vector<ull> a;
vector<ull> b;

void solve(){
    ull n, x, y; cin>>n>>x>>y;
    if(x>y) swap(x, y);

    ull d = y-x;

    ull di = n-1;

    //cout<<d<<" "<<di<<"\n";
    for(; di && d%di; di--);
    //cout<<di<<"\n";

    if(!di)
        di = y-x;
    else di = d/di;

    n -= 1;
    n -= d/di;
    //cout<<n<<"\n";
    if(n){
        ull k;
        k = min(n, (x-1)/di);
        x -= k*di;
        n -= k;
    }

    if(n){
        y += n*di;
    }

    for(int i = x; i<=y; i+=di)
        cout<<i<<" ";
    cout<<"\n";

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

/*
1
5 20 50

1
5 3 8
*/
