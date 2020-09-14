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

#define MAX 200100
#define MOD 1000000007

vector<bool> a;
vector<ull> b;
ull n;

ull dp[2][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n;

    for(int i=0; i<n; i++){
        bool z; cin>>z;
        a.push_back(z);
    }

    fill(dp[0], dp[0]+n+1, INT_MAX);
    fill(dp[1], dp[1]+n+1, INT_MAX);

    dp[0][0] = 0;
    for(int i = 0; i<n; i++){

        dp[1][i+1] = min(dp[1][i+1], dp[0][i] + a[i]);
        if(i<n-1)
            dp[1][i+2] = min(dp[1][i+2], dp[0][i] + a[i] + a[i+1]);

        dp[0][i+1] = min(dp[0][i+1], dp[1][i]);
        if(i<n-1)
            dp[0][i+2] = min(dp[0][i+2], dp[1][i]);
    }

    //for(int i = 0; i<=n; i++) cout<<dp[0][i]<<" "; cout<<"\n";
    //for(int i = 0; i<=n; i++) cout<<dp[1][i]<<" "; cout<<"\n";

    cout<< min(dp[0][n], dp[1][n])<<"\n";

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

