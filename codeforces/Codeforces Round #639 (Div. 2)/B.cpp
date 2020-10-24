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

#define MAX 30000
#define MOD 1000000007

ull dp[MAX];
ull n;

void solve(){

    cin>>n;

    int ans = 0;

    while(n){
        int pos = lower_bound(dp, dp+MAX, n) - dp;
        if(dp[pos]>n)pos--;

        if(pos>0){
            ans ++;
            n -= dp[pos];
        }
        else break;
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    dp[0] = 0;
    for(int i=1; i<MAX; i++)
        dp[i] = dp[i-1] + 2*i + (i-1);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

