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

#define MAX 400
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull R, C;
string s;

ull grid[MAX][MAX];

void solve(){
    cin>>R>>C;

    priority_queue<pair<ull, pii>> nxt; //height, position
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin>>grid[i][j];
            nxt.push({grid[i][j], {i, j}});
        }
    }

    vector<vector<bool>> selected(R+2, vector<bool>(C+2, false));

    ull ans = 0;
    while(nxt.size()){
        pii current = nxt.top().second;
        nxt.pop();

        if(current.first<1 || current.second<1 || current.first>R || current.second>C)
            continue;
        if(selected[current.first][current.second])
            continue;
        selected[current.first][current.second] = true;

        int i = current.first, j = current.second;

        if(i>1 && grid[i-1][j]<grid[i][j]){
            ans += (grid[i][j]-1)-grid[i-1][j];
            grid[i-1][j] = grid[i][j]-1;

            nxt.push({grid[i-1][j], {i-1, j}});
        }
        if(i<R && grid[i+1][j]<grid[i][j]){
            ans += (grid[i][j]-1)-grid[i+1][j];
            grid[i+1][j] = grid[i][j]-1;

            nxt.push({grid[i+1][j], {i+1, j}});
        }
        if(j>1 && grid[i][j-1]<grid[i][j]){
            ans += (grid[i][j]-1)-grid[i][j-1];
            grid[i][j-1] = grid[i][j]-1;

            nxt.push({grid[i][j-1], {i, j-1}});
        }
        if(j<C && grid[i][j+1]<grid[i][j]){
            ans += (grid[i][j]-1)-grid[i][j+1];
            grid[i][j+1] = grid[i][j]-1;

            nxt.push({grid[i][j+1], {i, j+1}});
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

