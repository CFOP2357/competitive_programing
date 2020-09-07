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

#define MAX 5010
#define MOD 1000000007

vector<ull> a;
ull n;

bool dp[MAX][MAX];

void solve(){
    a.clear();
    cin>>n;
    int last; cin>>last;
    a.push_back(1);
    for(int i = 1; i<2*n; i++){
        int z; cin>>z;
        if(z<last)
            a.back()++;
        else{
            a.push_back(1);
            last = z;
        }
    }

    for(int i = 0; i<=2*n; i++)
        fill(dp[i], dp[i]+n+1, false);

    for(int i = 0; i<a.size(); i++){
        dp[i][0]=true;
        for(int j=0; j<=n; j++){
            if(dp[i][j]){
                dp[i+1][j] = true;
                if(j+a[i]<=n)
                    dp[i+1][j+a[i]]=true;
            }
        }
    }

    if(dp[a.size()][n])
        cout<<"YES\n";
    else cout<<"NO\n";
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

/*
6
2
2 3 1 4
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7
*/
