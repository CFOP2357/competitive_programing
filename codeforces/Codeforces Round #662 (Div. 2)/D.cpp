#include <bits/stdc++.h>
using namespace std;

#define MAX 2005

char pat[MAX][MAX];
int dp[MAX][MAX];
int n, m;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>pat[i][j];

    for(int i=0; i<n; i++)
        dp[i][0] = dp[i][m-1] = 1;
    for(int i=0; i<m; i++)
        dp[0][i] = dp[n-1][i] = 1;

    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++){
            if(pat[i][j] == pat[i-1][j] &&  pat[i][j] == pat[i+1][j] && pat[i][j] == pat[i][j+1] &&  pat[i][j] == pat[i][j-1]){
                //si se puede ;v
                dp[i][j] = 2;
            }
            else { //no se puede
                dp[i][j]  = 1;
            }
        }
    }
    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++){
            if(pat[i][j] == pat[i-1][j] &&  pat[i][j] == pat[i+1][j] && pat[i][j] == pat[i][j+1] &&  pat[i][j] == pat[i][j-1]){
                dp[i][j] = dp[i-1][j]+1;
                dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
            }
        }
    }

    for(int i=n-1; i>0; i--){
        for(int j=m-1; j>0; j--){
            if(pat[i][j] == pat[i-1][j] &&  pat[i][j] == pat[i+1][j] && pat[i][j] == pat[i][j+1] &&  pat[i][j] == pat[i][j-1]){
                dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                dp[i][j] = min(dp[i][j+1]+1, dp[i][j]);
            }
        }
    }

    /*for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<< dp[i][j]<<" ";
        cout<<"\n";
    }*/


    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ans += dp[i][j];

    cout<<ans<<"\n";


}
