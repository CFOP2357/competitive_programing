#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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

#define MAX 100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, k;

char state[MAX][MAX];
char mapa[MAX][MAX];
vector<int> ship;
bool ocupado[10];


void printState(){
  for(int i = 0; i<n; i++){
    for(int j=0; j<n; j++)
      cout<<state[i][j];
    cout<<"\n";
  }
  char c;
  cin>>c;
}

bool validState(){
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(mapa[i][j]!='.' && state[i][j]!=mapa[i][j])
        return false;

  return true;
}

bool semiValid(int i, int j){
  return (state[i][j]=='.' or mapa[i][j]=='.'
  or mapa[i][j]==state[i][j]);
}

bool allVisited(){
  bool ans = true;
  for(int i = 0; i < k; i++)
    ans = ans and ocupado[i];

  return ans;
}

bool posiblePonerBarco(int x, int y, int longitud, int direccion){
  int cuantos = 0;
  if(direccion == 0){ //horizontal
    for(int i = 0; i < longitud; i++){
      if(y + i < n)
        cuantos += (state[x][y + i] == '.');
      if(mapa[x][y+i] == 'X')
        return false;
    }
  }
  if(direccion == 1){ //vertical
    for(int i = 0; i < longitud; i++){
      if(x + i < n)
        cuantos += (state[x + i][y] == '.');
      if(mapa[x+i][y] == 'X')
        return false;
    }
  }
  return cuantos == longitud;
}

void ponerBarco(int x, int y, int longitud, int direccion){
  if(direccion == 0){ //horizontal
    for(int i = 0; i < longitud; i++)
      state[x][y + i] = 'O';
  }
  if(direccion == 1){ //vertical
    for(int i = 0; i < longitud; i++)
        state[x + i][y] = 'O';
  }
}

void quitarBarco(int x, int y, int longitud, int direccion){
  if(direccion == 0){ //horizontal
    for(int i = 0; i < longitud; i++)
      state[x][y + i] = '.';
  }
  if(direccion == 1){ //vertical
    for(int i = 0; i < longitud; i++)
        state[x + i][y] = '.';
  }
}


ull search(int casilla) {

  int i = casilla / n;
  int j = casilla % n;

  ull partialans = 0;

 // cout<<casilla<<"\n";
  //printState();

  ull ans = 0;


  if(casilla>=n*n){
    //cout << validState() << ' ' << allVisited() << '\n';
    //printState();
    return validState() && allVisited();
  }

  //cout << "validState() && allVisited()\n";

  if(!semiValid(i, j))
    return 0;
  //cout<<"##\n";

  if(state[i][j] != '.')
    return search(casilla + 1);

    for(int s=0; s<k; s++){
      //cout << "Ciclo barcos\n";
      if(s>1 && ship[s-1]==ship[s] && not ocupado[s-1]){
        ans += partialans;
        continue;
      }

      partialans = 0;

      if(not ocupado[s]){
        ocupado[s] = true;

        if(posiblePonerBarco(i, j, ship[s], 1)){
          ponerBarco(i, j, ship[s], 1);
          partialans+=search(casilla+1);
          quitarBarco(i, j, ship[s], 1);

        }

        if(posiblePonerBarco(i, j, ship[s], 0) && ship[s]>1){
          ponerBarco(i, j, ship[s], 0);
          partialans+=search(casilla+1);
          quitarBarco(i, j, ship[s], 0);
        }

        ocupado[s] = false;
        ans += partialans;
      }
    }

  state[i][j] = 'X';
  ans += search(casilla+1);
  state[i][j] = '.';

  return ans;
}

void solve(){

    cin>>n>>k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>mapa[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          state[i][j] = '.';

    for(int i=0; i<k; i++)
    {
        int x;
        cin>>x;

        ship.push_back(x);
    }
    sort(all(ship));
    cout<<search(0)<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

/*
5 5
.....
.....
.....
.....
.....
2 2 2 2 2
*/
