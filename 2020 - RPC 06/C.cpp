//por Bernardo
#include <bits/stdc++.h>
using namespace std;

long n, m;

bool rect(long x){
  long top = ceil(sqrt(x));
  for(long i = 1; i <= top and i < n; i++)
    if(x % i == 0 and x / i < m){
      //cout << i << ' ' << x / i << '\n';
      return true;
    }
  return false;
}

int main(){
  long k;
  cin >> n >> m >> k;

  if(n > m) swap(n, m);

  if(k % m == 0 or k % n == 0)
    cout << "1\n";
  else if(rect(k) or rect((n * m) - k))
    cout << "2\n";
  else
    cout << "3\n";

  return 0;
}
