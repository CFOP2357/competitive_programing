#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_Update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_Update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 550
#define MOD 1000000007

ull N;
string s;

int A[MAX][MAX];
int currentGrid[MAX][MAX];
ull B[MAX][MAX];

ull R[MAX];
ull C[MAX];

ull ans;

bool solveGrid(){

    bool solved = false;

    for(int i=1; i<=N; i++){
        int toSolve = 0;
        for(int j=1; j<=N; j++)
            if(currentGrid[i][j]<0)
                toSolve++;

        if(toSolve==1){
            for(int j=1; j<=N; j++)
                if(currentGrid[i][j]<0)
                    currentGrid[i][j] = 1;
            solved = true;
        }
    }

    for(int j=1; j<=N; j++){
        int toSolve = 0;
        for(int i=1; i<=N; i++)
            if(currentGrid[i][j]<0)
                toSolve++;

        if(toSolve==1){
            for(int i=1; i<=N; i++)
                if(currentGrid[i][j]<0)
                    currentGrid[i][j] = 1;
            solved = true;
        }
    }

    return solved;
}

bool solved(){

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            currentGrid[i][j] = A[i][j];


    while(solveGrid());

    for(int i=1; i<=N; i++){
        int toSolve = 0;
        for(int j=1; j<=N; j++)
            if(currentGrid[i][j]<0)
                toSolve++;
        if(toSolve>1)
            return false;
    }

    for(int j=1; j<=N; j++){
        int toSolve = 0;
        for(int i=1; i<=N; i++)
            if(currentGrid[i][j]<0)
                toSolve++;
        if(toSolve>1)
            return false;
    }

    return true;

}

void bk(int i=1, int j=1, ull currentScore = 0){

    if(j>N){
        j=1;
        i++;
    }

    if(solved()){
        ans = min(ans, currentScore);
        return;
    }

    if(i>N)
        return;

    bk(i, j+1, currentScore);

    if(A[i][j] < 0){
        A[i][j] = 1;
        bk(i, j+1, currentScore+B[i][j]);
        A[i][j] = -1;
    }

}

void solve(){
    cin>>N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>A[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>B[i][j];
        }
    }

    for(int i=1; i<=N; i++)
        cin>>R[i];

    for(int i=1; i<=N; i++)
        cin>>C[i];

    ans = LLONG_MAX;
    bk();

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

