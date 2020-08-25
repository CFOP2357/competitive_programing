#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 3010
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> b;

ull dp[MAX][MAX];
ull dp2[MAX][MAX];

void solve(){
    int n; cin>>n;
    a.clear();
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            dp[i][j] = 0;
            dp2[i][j]=0;
        }

    for(int i=0; i<n; i++){
        dp[i][i] = 0;
        for(int j=i+1; j<n; j++){
            dp[i][j] = dp[i][j-1];
            dp[i][j] += a[i]==a[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]!=a[j]){
                dp2[i][j]  = dp2[i][j-1] + dp[j][n-1];
            }
            else  dp2[i][j]  = dp2[i][j-1];
        }
    }

    ull ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]!=a[j]){
                ans += dp2[i][j];
            }
            else {
                ans += ((dp[j][n-1]-1)*(dp[j][n-1]-2)) / 2;
            }
        }
    }

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
