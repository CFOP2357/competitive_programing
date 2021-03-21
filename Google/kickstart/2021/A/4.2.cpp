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
ull B[MAX][MAX];

ull R[MAX];
ull C[MAX];

ull ans;

priority_queue<pair<ull, pii>, vector<pair<ull, pii>>, greater<pair<ull, pii>>> nxt; //cost, {type, pos}

vector<bool> selectedR;
vector<bool> selectedC;

#define TR 1
#define TC 0

ull costR(int i){
    ull maxCost = 0;
    ull cost = 0;
    for(int j=1; j<=N; j++){

        if(A[i][j]<0){
            cost += B[i][j];
            maxCost = max(maxCost, B[i][j]);
        }

    }

    return cost - maxCost;
}

ull costC(int j){
    ull maxCost = 0;
    ull cost = 0;
    for(int i=1; i<=N; i++){

        if(A[i][j]<0){
            cost += B[i][j];
            maxCost = max(maxCost, B[i][j]);
        }

    }

    return cost - maxCost;
}

void solveR(int i){
    ull maxCost = 0;
    ull cost = 0;
    for(int j=1; j<=N; j++){

        if(A[i][j]<0){
            cost += B[i][j];
            maxCost = max(maxCost, B[i][j]);
            A[i][j] = 1;

            nxt.push({ costC(j), {TC, j} });
        }

    }

    ans += cost - maxCost;
}

void solveC(int j){
    ull maxCost = 0;
    ull cost = 0;
    for(int i=1; i<=N; i++){

        if(A[i][j]<0){
            cost += B[i][j];
            maxCost = max(maxCost, B[i][j]);
            A[i][j] = 1;

            nxt.push({ costR(i), {TR, i} });
        }

    }

    ans += cost - maxCost;
}


bool solveGrid(){

    bool solved = false;

    for(int i=1; i<=N; i++){
        int toSolve = 0;
        for(int j=1; j<=N; j++)
            if(A[i][j]<0)
                toSolve++;

        if(toSolve==1){
            for(int j=1; j<=N; j++)
                if(A[i][j]<0){
                    A[i][j] = 1;
                    nxt.push({ costC(j), {TC, j} });
                }
            solved = true;
            selectedR[i] = true;
        }
    }

    for(int j=1; j<=N; j++){
        int toSolve = 0;
        for(int i=1; i<=N; i++)
            if(A[i][j]<0)
                toSolve++;

        if(toSolve==1){
            for(int i=1; i<=N; i++)
                if(A[i][j]<0){
                    A[i][j] = 1;
                    nxt.push({ costR(i), {TR, i} });
                }
            solved = true;
            selectedC[j] = true;
        }
    }

    return solved;
}

bool solved(){

    while(solveGrid());

    for(int i=1; i<=N; i++){
        int toSolve = 0;
        for(int j=1; j<=N; j++)
            if(A[i][j]<0)
                toSolve++;
        if(toSolve>1)
            return false;
    }

    for(int j=1; j<=N; j++){
        int toSolve = 0;
        for(int i=1; i<=N; i++)
            if(A[i][j]<0)
                toSolve++;
        if(toSolve>1)
            return false;
    }

    return true;

}

void solve(){
    cin>>N;

    while(nxt.size())nxt.pop();

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

    for(int i=1; i<=N; i++){
        cin>>R[i];
        nxt.push({costR(i), {TR, i}});
    }

    for(int j=1; j<=N; j++){
        cin>>C[j];
        nxt.push({costC(j), {TC, j}});
    }

    ans = 0;

    selectedC.assign(N+1, 0);
    selectedR.assign(N+1, 0);

    while(nxt.size() && !solved()){

        int tp = nxt.top().second.first;
        int pos = nxt.top().second.second;
        nxt.pop();

        //cout<<tp<<" "<<pos<<" "<<selectedR[pos]<<"$$\n";

        if(tp == TR && selectedR[pos])
            continue;
        if(tp == TC && selectedC[pos])
            continue;

        if(tp == TR)
            selectedR[pos] = true;
        if(tp == TC)
            selectedC[pos] = true;


        if(tp == TR)
            solveR(pos);
        if(tp == TC)
            solveC(pos);

        for(int i=1; i<=N; i++){
            nxt.push({costC(i), {TC, i}});
            nxt.push({costR(i), {TR, i}});
        }
    }

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

/*
1
2
-1 -1
-1 -1
1 10
100 1000
1 0
0 1
*/
