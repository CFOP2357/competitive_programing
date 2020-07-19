//por Bernardo
#include <bits/stdc++.h>
using namespace std;

int dis(char c, char C){
  int x = abs((c - 'a') % 9 - (C - 'a') % 9);
  int y = abs((c - 'a') / 9 - (C - 'a') / 9);
  return max(x, y);
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  int n, d;

  cin >> n;

  while(n--){
    cin >> a >> b;

    if(a.size() == b.size()){
      d = 0;
      for(int i = 0; i < a.size() and d < 2; i++)
        d = max(d, dis(a[i], b[i]));
      d = min(2, d);

      cout << d + 1 << '\n';
    } else {
      cout << "3\n";
    }
  }
  return 0;
}
