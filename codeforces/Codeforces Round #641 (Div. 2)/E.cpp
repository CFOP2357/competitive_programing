#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005; // 1e3 + 5

#define COORD pair<int, int>
#define X first
#define Y second

typedef long long ull;

bool grid[MAX][MAX];
ull T[MAX][MAX];

ull n, m, t;

queue<COORD>Cola;

int ejex[] = {-1,  0, 1, 0},
    ejey[] = { 0, -1, 0, 1};

void bfs(){
  while(Cola.size()){
    COORD tope = Cola.front();
    Cola.pop();
    for(int i = 0; i < 4; i++){
      COORD aux = tope;
      aux.X += ejex[i];
      aux.Y += ejey[i];
      //dentro de limites
      if(aux.X > -1 && aux.X < n && aux.Y > -1 && aux.Y < m){
        if(T[aux.X][aux.Y] == 0){
          T[aux.X][aux.Y] = T[tope.X][tope.Y] + 1;
          Cola.push(aux);
        }
      }
    }
  }
  /*Debbug*/
  /*for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
        cout<<T[i][j]<<" ";
    cout<<"\n";
  }*/
}

int main() {

  ios_base::sync_with_stdio(0); cin.tie(0);
  //leer
  string s;
  cin>>n>>m>>t;
  for(int i =0; i<n; i++){
    cin>>s;
    for(int j=0; j<m; j++)
      grid[i][j] = s[j] == '1';
  }

  //los unos
    for(int i =0; i<n; i++)
      for(int j=0; j<m; j++)
        if( (i>0 && grid[i-1][j] == grid[i][j]) ||
            (i<n-1 && grid[i+1][j] == grid[i][j]) ||
            (j>0 && grid[i][j-1] == grid[i][j]) ||
            (j<m-1 && grid[i][j+1] == grid[i][j])
          )
          T[i][j] = 1;

  //poner unos en cola
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(T[i][j])
          Cola.push({i, j});

  //cout << "antes de la BFS\n";
  //bfs
  bfs();
  //cout << "despues de la BFS\n";
  //contestar querys


  while(t--){
    ull i,j,p;
    cin >> i >> j >> p; i--, j--;
    if(p < T[i][j] or T[i][j] == 0){
      cout << grid[i][j] << '\n';
    }else {
      if((p - T[i][j]) % 2)
        cout << grid[i][j] << '\n';
      else
        cout << not grid[i][j] << '\n';
    }
  }
}

/*
5 5 1
1 0 1
0 1 0
1 0 1
1 1 20

3 3 3
000
111
000
1 1 1
2 2 2
3 3 3

5 2 2
01
10
01
10
01
1 1 4
5 1 4

5 5 3
01011
10110
01101
11010
10101
1 1 4
1 2 3
5 5 3

5 5 3
01011
10110
01101
11000
10101
1 1 4
1 2 3
5 5 3
5 5 10

1 1 3
0
1 1 1
1 1 2
1 1 3
*/
