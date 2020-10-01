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

#define MAX 60

ull n, m;
int g = 0;

char grid[MAX][MAX];
vector<vector<bool>>visited(MAX);

bool dfs1(int i, int j){
    if(i>=n || i<0 || j>=m || j<0)
        return true;
    if(grid[i][j]=='#')
        return true;
    if(grid[i][j]=='B')
        return false;

    if(visited[i][j])
        return true;
    visited[i][j] = true;

    bool toCut = dfs1(i+1, j) && dfs1(i-1, j) && dfs1(i, j+1) && dfs1(i, j-1);

    if(!toCut){
        if(grid[i][j] == '.'){
            grid[i][j] = '#';
            return true;
        }
        return false;
    }

    return true;
}

bool dfs2(int i, int j){
    if(i>=n || i<0 || j>=m || j<0)
        return true;
    if(grid[i][j]=='#')
        return true;
    if(grid[i][j]=='B')
        return false;

    if(visited[i][j])
        return true;
    visited[i][j] = true;

    bool toCut = dfs2(i+1, j) && dfs2(i-1, j) && dfs2(i, j+1) && dfs2(i, j-1);

    if(!toCut){
        return false;
    }

    if(grid[i][j] == 'G')
        g--;

    return true;
}

void solve(){
    cin>>n>>m;

    fill(all(visited), vector<bool>(MAX, false));

    g = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='G') g++;
        }
    }

    dfs1(n-1, m-1);

    //cout<<g<<"\n";

    fill(all(visited), vector<bool>(MAX, false));

    if(dfs2(n-1, m-1) && !g)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    //cout<<g<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
2 2
#B
B.
*/
