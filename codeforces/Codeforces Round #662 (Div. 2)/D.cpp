#include <bits/stdc++.h>
using namespace std;

#define MAX 2005

char mapa[MAX][MAX];
int ss[MAX][MAX];
int n, m;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(ss[i][j]) continue;
            dfs(i, j);
        }
}
