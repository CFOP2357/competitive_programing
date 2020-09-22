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

#define MAX 200100
#define MOD 1000000007

ull n, k;
int dp[MAX];

void solve(){
    cin>>n>>k;
    string s; cin>>s;

    vector<bool> posible(n, true);

    int j = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1')
            j = k+1;
        if(j){
            j--;
            posible[i]=false;
        }
    }

    j = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i] == '1')
            j = k+1;
        if(j){
            j--;
            posible[i]=false;
        }
    }

    fill(dp, dp+n+5, 0);
    for(int i = 0; i<n; i++){
        dp[i+1] = max(dp[i], dp[i+1]);
        if(posible[i]){
            dp[min(i+k+1, n)] = max(dp[i]+1, dp[min(i+k+1, n)]);
        }
    }

    cout<<dp[n]<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

