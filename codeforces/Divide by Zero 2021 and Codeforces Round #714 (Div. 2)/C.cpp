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

typedef int ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 200010
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

ull dp[10][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;

    ull ans = 0;

    while(n){

        ans += dp[n%10][m];
        ans %= MOD;

        n/=10;

    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    for(ull i=0; i<10; i++){

        vector<ull> cont(10, 0);
        cont[i] = 1;
        for(ull j=0; j<MAX; j++){

            ull ans = 0;
            for(auto p : cont){
                ans += p;
                ans %= MOD;
            }

            dp[i][j] = ans;


            vector<ull> nxt(10, 0);

            for(int k=0; k<9; k++)
                nxt[k+1] = cont[k];

            nxt[0] += cont[9];
            nxt[0] %= MOD;
            nxt[1] += cont[9];
            nxt[1] %= MOD;

            for(int k=0; k<=9; k++)
                cont[k] = nxt[k];

        }

    }

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

