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

#define MAX 1005
#define MOD 1000000007

char grid[MAX][MAX];
bool visited[MAX][MAX];
ull n, m;

void _fill(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    if(grid[i][j]=='.')
        return;
    if(visited[i][j])
        return;
    visited[i][j] = true;

    _fill(i+1, j);
    _fill(i-1, j);
    _fill(i, j+1);
    _fill(i, j-1);
}

ull f(){
    ull ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visited[i][j] && grid[i][j]=='#'){
                ans++;
                _fill(i, j);
            }
    return ans;
}

void solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];

    bool rEmpty(true), cEmpty(true);

    for(int i=0; i<n; i++){
        bool enc = false, enc2 = false;

        for(int j=0; j<m; j++){
            if(grid[i][j]=='.' && enc == true)
                enc2=true;
            if(grid[i][j]=='#' && enc == false)
                enc=true;
            if(grid[i][j]=='#' && enc2 == true){
                cout<<"-1\n";
                return;
            }
        }

        rEmpty = rEmpty && enc;
    }

    for(int j=0; j<m; j++){
        bool enc = false, enc2 = false;

        for(int i=0; i<n; i++){
            if(grid[i][j]=='.' && enc == true)
                enc2=true;
            if(grid[i][j]=='#' && enc == false)
                enc=true;
            if(grid[i][j]=='#' && enc2 == true){
                cout<<"-1\n";
                return;
            }
        }

        cEmpty = cEmpty && enc;
    }

    if(rEmpty!=cEmpty){
        cout<<"-1\n";
        return;
    }

    cout<<f()<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

