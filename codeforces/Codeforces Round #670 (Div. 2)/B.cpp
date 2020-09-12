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

#define MAX 500100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

ull dp[10][MAX]; //max
ull dp2[10][MAX]; //min

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    for(int i=0; i<6; i++) fill(dp[i], dp[i]+n+1, LLONG_MIN);
    for(int i=0; i<6; i++) fill(dp2[i], dp2[i]+n+1, LLONG_MAX);

    fill(dp[0], dp[0]+n+1, 1);
    fill(dp2[0], dp2[0]+n+1, 1);

    for(int i=0; i<5; i++){
        for(int j=0; j<n; j++){
            if(j>0){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                dp2[i][j] = min(dp2[i][j], dp2[i][j-1]);
            }
            if(dp[i][j] != LLONG_MIN){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]*a[j]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp2[i][j]*a[j]);

                dp2[i+1][j+1] = min(dp2[i+1][j+1], dp[i][j]*a[j]);
                dp2[i+1][j+1] = min(dp2[i+1][j+1], dp2[i][j]*a[j]);
            }
        }
    }

    /*for(int i=0; i<6; i++){
        for(int j=0; j<=n; j++){
            if(dp[i][j]!=LLONG_MIN)
                cout<<dp[i][j]<<" ";
            else cout<<"# ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    for(int i=0; i<6; i++){
        for(int j=0; j<=n; j++){
            if(dp2[i][j]!=LLONG_MAX)
                cout<<dp2[i][j]<<" ";
            else cout<<"# ";
        }
        cout<<"\n";
    }*/

    cout<<*max_element(dp[5], dp[5]+n+1)<<"\n";
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
1
6
-1 -2 -3 1 2 -1
*/
