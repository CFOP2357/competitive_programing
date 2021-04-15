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

#include <time.h>

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

#define MAX 200
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

ull dp[MAX][MAX][MAX][2];

void solve(){

    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            for(int k = 0; k<MAX; k++)
                dp[i][j][k][0] = dp[i][j][k][1] = INT_MAX;


    cin>>n;
    ull even = n/2, odd = n/2 + n%2;
    for(int i=0; i<n; i++){
        ull z; cin>>z;

        a.push_back(z);

        if(z>0){
            if(z%2)
                odd--;
            else
                even--;
        }
    }


    dp[0][odd][even][0] = dp[0][odd][even][1] = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=odd; j++)
            for(int k = 0; k<=even; k++){

                if(a[i]){

                    if(a[i]&1)//odd
                        dp[i+1][j][k][1] = min({dp[i+1][j][k][1], dp[i][j][k][0]+1, dp[i][j][k][1]});
                    else
                        dp[i+1][j][k][0] = min({dp[i+1][j][k][0], dp[i][j][k][0], dp[i][j][k][1]+1});

                    continue;
                }

                if(j>0)
                    dp[i+1][j-1][k][1] = min({dp[i+1][j-1][k][1], dp[i][j][k][0]+1, dp[i][j][k][1]});
                if(k>0)
                    dp[i+1][j][k-1][0] = min({dp[i+1][j][k-1][0], dp[i][j][k][0], dp[i][j][k][1]+1});

            }

    ull ans = ans = min(dp[n][0][0][0], dp[n][0][0][1]);

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

