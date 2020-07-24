#include <bits/stdc++.h>
#define MAX 30
using namespace std;

char grid[MAX][MAX];
int n;

void column(int c){
    int white=0, black=0, consecutiveWhite=0, consecutiveBlack=0;

    for(int i=0; i<n; i++){
        if(grid[i][c]=='W'){
            white++;
            consecutiveWhite++;
            consecutiveBlack=0;
            if(consecutiveWhite>=3){
                cout<<0<<"\n";
                exit(0);
            }
        }
        if(grid[i][c]=='B'){
            black++;
            consecutiveBlack++;
            consecutiveWhite=0;
            if(consecutiveBlack>=3){
                cout<<0<<"\n";
                exit(0);
            }
        }
    }

    if(white!=black){
        cout<<0<<"\n";
        exit(0);
    }
}

void row(int c){
    int white=0, black=0, consecutiveWhite=0, consecutiveBlack=0;

    for(int i=0; i<n; i++){
        if(grid[c][i]=='W'){
            white++;
            consecutiveWhite++;
            consecutiveBlack=0;
            if(consecutiveWhite>=3){
                cout<<0<<"\n";
                exit(0);
            }
        }
        if(grid[c][i]=='B'){
            black++;
            consecutiveBlack++;
            consecutiveWhite=0;
            if(consecutiveBlack>=3){
                cout<<0<<"\n";
                exit(0);
            }
        }
    }

    if(white!=black){
        cout<<0<<"\n";
        exit(0);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];

    for(int i=0; i<n; i++)
        column(i);
    for(int i=0; i<n; i++)
        row(i);

    cout<<1<<"\n";
    return 0;
}

/*
    6
    WWWBBB
    WWWBBB
    WWWBBB
    BBBWWW
    BBBWWW
    BBBWWW
*/
