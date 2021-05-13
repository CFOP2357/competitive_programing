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

#define MAX 10010
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, k;
string s;

bool dp[110][110][MAX];

void solve(){
    cin>>n>>m>>k;
    if(dp[n][m][k])
        cout<<"YES\n";
    else
        cout<<"NO\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    dp[1][1][0]=true;
    for(int x=1; x<=100; x++)
        for(int y=1; y<=100; y++){
            for(int k = 0; k<MAX; k++){
                if(dp[x][y][k]){
                    if(k+y<MAX)
                        dp[x+1][y][k+y] = true;
                    if(k+x<MAX)
                        dp[x][y+1][k+x] = true;
                }
            }
        }

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

