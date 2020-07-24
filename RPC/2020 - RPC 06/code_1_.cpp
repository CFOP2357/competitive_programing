//por Bernardo
#include <bits/stdc++.h>
using namespace std;

int temp[55];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m = 41, d = 1;
  int i = 0, j = 2;

  cin >> n;

  for(int k = 0; k < n; k++)
    cin >> temp[k];

  while(j < n){

    if(m > max(temp[i],temp[j])){
      m =  max(temp[i],temp[j]);
      d = i + 1;
    }

    i++;j++;
  }

  cout << d << ' ' << m << '\n';

  return 0;
}
/*
5
23 27 31 28 30
*/

