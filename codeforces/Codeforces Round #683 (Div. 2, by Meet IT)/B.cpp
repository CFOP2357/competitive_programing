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

#define MAX 20
#define MOD 1000000007

ull grid[MAX][MAX];

int n, m;

void solve(){
    cin>>n>>m;
    ull ans = 0;
    ull min_abs = INT_MAX;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            ans += abs(grid[i][j]);
            min_abs = min(abs(grid[i][j]), min_abs);
        }

    //cout<<ans<<"#\n";

    int neg = 0;
    bool zero = false;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j]<0){
                neg++;
            }
            else if(grid[i][j]==0)
                zero = true;

    //cout<<ans<<" "<<min_abs<<"#\n";

    if(neg%2 && !zero){
        ans -= 2*min_abs;
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

