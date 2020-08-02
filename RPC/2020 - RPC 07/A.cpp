#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

int d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[MAX];

int main() {
  for(int i=0; i<10; i++)
    dp[d[i]] = max(dp[d[i]], i);

  for(int i=0; i<MAX; i++){
    if(!dp[i]) continue;
    for(int j=0; j<10; j++)
      if(d[j]+i<MAX)
        dp[d[j]+i] = max(dp[d[j]+i], dp[i]+j);
  }

  int n; cin>>n;
  cout<<dp[n]<<"\n";
  return 0;
}