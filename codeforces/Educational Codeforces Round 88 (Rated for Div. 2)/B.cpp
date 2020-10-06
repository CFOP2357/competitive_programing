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

#define MAX 1000100
#define MOD 1000000007

vector<ull> dp;
ull n, m, x, y;

void solve(){
    cin>>n>>m>>x>>y;
    ull ans = 0;
    for(int i=0; i<n; i++){
        dp.assign(m+1, LLONG_MAX);
        dp[0] = 0;
        string row; cin>>row;

        for(int j = 0; j<m; j++){
            if(row[j] == '.'){
                dp[j+1] = min(dp[j+1], dp[j] + x);
                if(j<m-1 && row[j+1]=='.'){
                    dp[j+2] = min(dp[j+2], dp[j] + y);
                }
            }
            else dp[j+1] = min(dp[j+1], dp[j]);
        }

        ans += dp[m];

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

