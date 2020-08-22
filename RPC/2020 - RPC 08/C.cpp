#include <iostream>
using namespace std;
#define MAX 5001
#define MOD 1000000007

typedef int ull;
int d[MAX];
ull comb[MAX][MAX]; //n, k
ull ans[MAX][MAX]; //n, k
ull edges[MAX][MAX]; //n, k

void preCalc(){
  for(int i=1; i<MAX; i++){
    int j = 1;
    for(j=1; j*j<i; j++){
      if(i%j == 0)d[i]++;
    }
    d[i]*=2;
    if(j*j==i)d[i]++;
    d[i]--;
  }

  comb[1][1]=comb[0][1]=comb[1][2]=1;
  for(int i=1; i<MAX; i++){
     comb[i][1] = 1;
     for(int j=2; j<=i; j++){
        comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        comb[i][j]%=MOD;
     }
  }

  for(int k = 1; k<MAX; k++){
      edges[1][k] =  min(d[1], k);
      for(int i = 2; i<MAX; i++){
        edges[i][k] = min(d[i], k) + edges[i-1][k];
        edges[i][k] %= MOD;
      }
  }

  for(int k = 1; k<MAX; k++){
      ull ans = 1;
      for(int i = 1; i<MAX; i++){
        if(d[i]>k){
            ull p = comb[d[i]][k];
            p%=MOD;
            ans *= p;
            ans %= MOD;
        }
        ::ans[i][k] = ans;
      }
  }
}


int main(){
  /*ios_base::sync_with_stdio(0);
  cin.tie(0);*/

  preCalc();

  int t; scanf("%d", &t);
  while(t--){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    printf("%d %d\n", edges[n][k], ans[n][k]);
  }

  return 0;
}


/*
3
4 2
5 3
6 2
*/


