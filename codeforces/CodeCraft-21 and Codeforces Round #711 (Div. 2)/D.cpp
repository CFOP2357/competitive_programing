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

#define MAX (long double)100000.00
#define MOD 1000000007

ull n, m;
string s;

ull type1(ull k, ull x){
    long double ans = (long double)k + ((long double)x)/MAX;
    ans = ceil(ans);
    return ans;
}

ull type2(ull k, ull x){
    long double ans = k * x;
    ans /= MAX;
    ans = ceil(ans);
    return ans;
}

void solve(){

    cin>>n>>m;

    vector<ull> ans(m+1, -1);

    ans[0] = 0;
    for(int i=1; i<=n; i++){

        ull t, x, y; cin>>t>>x>>y;

        for(ull j=0; j<=m; j++){
            if(ans[j]<0 || ans[j]==i)
                continue;

            ull p;
            if(t==1)
                p = type1(j, x);
            else
                p = type2(j, x);

            for(ull a = 1; a<=y && p<=m && ans[p]<0; a++, p = (t==1)?type1(p, x):type2(p, x)){
                ans[p] = i;
            }

        }

    }

    for(int i=1; i<=m; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

