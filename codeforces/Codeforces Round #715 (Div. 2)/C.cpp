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

#define MAX 2500
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

ull dp[MAX][MAX];
ull D[MAX][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    sort(all(a));

    for(int i=0; i<=n; i++){
        D[i][i] = 0;
        for(int j=0; i+j<=n; j++){
            dp[i+j][i] = dp[i][i+j] = LLONG_MAX;

            if(j>0)
                D[i+j][i] = D[i][i+j] = D[i][i+j-1] + abs(a[i+j]-a[i+j-1]);
        }
    }

    /*cout<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<D[i][j]<<" ";
        cout<<"\n";
    }cout<<"\n";*/

    for(int i = 0; i<n; i++){
        dp[i][i] = 0;

    }

    for(int j = 1; j<n; j++)
        for(int i=0; i<n; i++){

                if(i+j < n)
                    dp[i+j][i] = dp[i][i+j] = min(dp[i][i+j], dp[i][i+j-1] + D[i][i+j]);

                if(i-j >= 0)
                    dp[i-j][i] = dp[i][i-j] = min(dp[i][i-j], dp[i][i-j+1] + D[i-j][i]);

        }

    /*cout<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }cout<<"\n";*/

    cout<<dp[0][n-1]<<"\n";
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

