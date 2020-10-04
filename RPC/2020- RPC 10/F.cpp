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

int dp[MAX][MAX][MAX]; //a, b, c, s

void solve(){
    string a, b, c;
    string s;
    cin>>a>>b>>c;
    cin>>s;

    dp[0][0][0] = 1;
    //cout<<dp[z][0][0][0]<<" "<< (dp[!z][0][0][0] += dp[z][0][0][0]) <<"\n";
    for(int j=0; j<=a.size(); j++){
        for(int k=0; k<=b.size(); k++){
            for(int l=0; l<=c.size(); l++){
                if(j<a.size() && s[j+k+l] == a[j]){
                    dp[j+1][k][l] += dp[j][k][l];
                    dp[j+1][k][l] %= MOD;
                }
                if(k<b.size() && s[j+k+l] == b[k]){
                    dp[j][k+1][l] += dp[j][k][l];
                    dp[j][k+1][l] %= MOD;
                }
                if(l<c.size() && s[j+k+l] == c[l]){
                    dp[j][k][l+1] += dp[j][k][l];
                    dp[j][k][l+1] %= MOD;
                }
            }
        }
    }

    cout<<dp[a.size()][b.size()][c.size()]<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}
/*
eat
more
chicken
chimeacorkteen

*/

