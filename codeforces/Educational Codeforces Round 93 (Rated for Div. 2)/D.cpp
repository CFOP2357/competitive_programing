#include <bits/stdc++.h>
using namespace std;

#define MAX 210
#define MOD 1000000007

typedef int ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> r;
vector <ull> g;
vector <ull> b;

int dp[MAX][MAX][MAX];

void solve(){
    int R, G, B;
    cin>>R>>G>>B;

    for(int i=0; i<R; i++){
        int z; cin>>z;
        r.push_back(z);
    }
    for(int i=0; i<G; i++){
        int z; cin>>z;
        g.push_back(z);
    }
    for(int i=0; i<B; i++){
        int z; cin>>z;
        b.push_back(z);
    }

    sort(r.begin(), r.end(), greater<int>());
    sort(g.begin(), g.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int ans = 0;
    for(int i=0; i<=R; i++)
        for(int j=0; j<=G; j++)
            for(int k=0; k<=B; k++){
                ans = max(ans, dp[i][j][k]);
                if(j<G && k<B)
                    dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + g[j]*b[k]);
                if(i<R && k<B)
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + r[i]*b[k]);
                if(j<G && i<R)
                    dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + r[i]*g[j]);
            }


    cout<<ans<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}

/*
9 4 7
17 19 19 9 20 6 1 14 11
15 12 10 20
15 10 3 20 1 16 7

20 19 19 17 14 11 9 6 1
20 15 12 19
20 16 15 10 7 3 1
*/
