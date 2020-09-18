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

#define MAX 2001000
#define MOD 1000000007

ull n;
ull dp[MAX];

void solve(){
    cin>>n;
    cout<<dp[n]<<"\n";
}

void pre(){
    //dp[3] = dp[4] = 4;
    for(int i = 3; i<=MAX; i++){
        dp[i] = dp[i-1] + (2*dp[i-2]);
        if(i%3 == 0)dp[i]+=4;
        dp[i] %= MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    pre();
    while(t--){
        solve();
    }
    return 0;
}

