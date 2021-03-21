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

#define MAX 1010
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull R, C;
string s;

ull grid[MAX][MAX];

ull Left[MAX][MAX];
ull Right[MAX][MAX];
ull Up[MAX][MAX];
ull Down[MAX][MAX];

void solve(){
    cin>>R>>C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++)
            cin>>grid[i][j];
    }

    for(int i=1; i<=R+1; i++){
        for(int j=1; j<=C+1; j++){
            Left[i][j]=0;
            Right[i][j]=0;
            Down[i][j]=0;
            Up[i][j]=0;
        }
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(grid[i][j]){
                Down[i][j] = Down[i-1][j] + 1;
                Right[i][j] = Right[i][j-1] + 1;
            }
        }
    }

    for(int i=R; i>=1; i--){
        for(int j=C; j>=1; j--){
            if(grid[i][j]){
                Up[i][j] = Up[i+1][j] + 1;
                Left[i][j] = Left[i][j+1] + 1;
            }
        }
    }

    ull ans = 0;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++)
            if(grid[i][j]){


                ans += max(min(Right[i][j], Down[i][j]/2)-1, (ull)0);
                ans += max(min(Right[i][j]/2, Down[i][j])-1, (ull)0);

                ans += max(min(Left[i][j], Down[i][j]/2)-1, (ull)0);
                ans += max(min(Left[i][j]/2, Down[i][j])-1, (ull)0);


                ans += max(min(Right[i][j], Up[i][j]/2)-1, (ull)0);
                ans += max(min(Right[i][j]/2, Up[i][j])-1, (ull)0);

                ans += max(min(Left[i][j], Up[i][j]/2)-1, (ull)0);
                ans += max(min(Left[i][j]/2, Up[i][j])-1, (ull)0);

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

