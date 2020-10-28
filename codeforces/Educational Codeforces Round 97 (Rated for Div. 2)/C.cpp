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

#define MAX 500
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

ull dp[MAX][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        fill(dp[i], dp[i]+MAX, LLONG_MAX);
    }
    fill(dp[n], dp[n]+MAX, LLONG_MAX);

    sort(all(a));

    fill(dp[0]+1, dp[0]+MAX, 0);
    for(int i=0; i<n; i++)
        for(int j=1; j<MAX-1; j++){
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            if(dp[i][j]<LLONG_MAX)
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+abs(a[i]-j));
        }

    cout<<*min_element(dp[n], dp[n]+MAX)<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

