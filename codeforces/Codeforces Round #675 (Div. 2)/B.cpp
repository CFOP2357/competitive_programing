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

#define MAX 105
#define MOD 1000000007

ull n, m;

ull grid[MAX][MAX];

void solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>grid[i][j];

    ull ans = 0;//cout<<"\n";
    for(int i=0; i<n/2 + n%2; i++)
        for(int j = 0; j<m/2 + m%2; j++){
            vector<ull> a = {grid[i][j], grid[n-i-1][j], grid[n-i-1][m-j-1], grid[i][m-j-1]};
            sort(all(a));
            ull M = (a[1]+a[2])/2;
            ull d = 0;
            for(int k : a)
                d += abs(k-M);
            if(i == n/2)
                d -= abs(M - grid[i][j]) + abs(M - grid[i][m-j-1]);
            if(j == m/2)
                d -= abs(M - grid[i][j]) + abs(M - grid[n-i-1][j]);
            ans += d;

            //cout<<i<<" "<<j<<" "<<M<<" "<<d<<"\n";
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
3 4
1 2 3 4
5 6 7 8
9 10 11 18
*/
