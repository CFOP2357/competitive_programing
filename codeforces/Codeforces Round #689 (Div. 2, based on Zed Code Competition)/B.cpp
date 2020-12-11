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

#define MAX 600
#define MOD 1000000007

ull n, m;

char grid[MAX][MAX];
ull sum[MAX][MAX];

ull K(int i, int j){

    ull sz = 1;
    for(int k = 0; ;k++){
        if(i+k>n)
            return k;
        if(j-k<0 || j+k>m)
            return k;
        if(sum[i+k][j+k]-sum[i+k][j-k-1]!=sz)
            return k;
        sz+=2;
    }

    return 0;
}

void solve(){

    cin>>n>>m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>grid[i][j];

    for(int i=1; i<=n; i++){
        sum[i][0] = 0;
        sum[i][1] = (ull)(grid[i][1]=='*');
        //cout<<sum[i][1]<<" ";
        for(int j=2; j<=m; j++){
            sum[i][j] = sum[i][j-1]+(ull)(grid[i][j]=='*');
            //cout<<sum[i][j]<<" ";
        } //cout<<"\n";
    }

    ull ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            //cout<<i<<" "<<j<<" -> "<<K(i, j)<<"\n";
            ans+=K(i, j);
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

/*
1
2 3
.*.
***
*/
