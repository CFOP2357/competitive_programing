//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

const int MAX = 2000; //10^6
const int MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m, k, q;
string s;

char grid[MAX][MAX];
int ans[MAX][MAX];

void solve(){
    a.clear(); b.clear();

    int row, column;
    cin>>n>>m;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            cin>>grid[i][j];

            if(grid[i][j] == 'E'){
                row = i;
                column = j;
            }
        }
    }

    queue<pair<int, pii>> bfs;
    bfs.push({1, {row, column}});

    while(bfs.size()){
        auto [dis, pos] = bfs.front();
        row = pos.first;
        column = pos.second;
        bfs.pop();

        //cout<<row<<" "<<column<<"%\n";

        if(row <= 0 or row > n or column <= 0 or column > m)
            continue;

        if(ans[row][column])
            continue;

        if(grid[row][column] != '.' and grid[row][column] != 'E')
            continue;

        ans[row][column] = dis+1;
        //cout<<dis<<"$\n";
        bfs.push({dis+1, {row+1, column}});
        bfs.push({dis+1, {row-1, column}});
        bfs.push({dis+1, {row, column+1}});
        bfs.push({dis+1, {row, column-1}});

        //cout<<row<<" "<<column<<"\n";

    }

    /*rep(i, 1, n+1){
        rep(j, 1, m+1){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    cin>>q;
    while(q--){
        int row, column; cin>>row>>column;
        if(row <= 0 or row > n or column <= 0 or column > m){
            cout<<"?\n";
            continue;
        }

        if(grid[row][column] == '#')
            cout<<"W\n";
        else if(grid[row][column] == 'X')
            cout<<"X\n";
        else if(grid[row][column] == 'E')
            cout<<"E\n";
        else if(grid[row][column] == '.'){
            if(ans[row][column]){
                if(ans[row][column-1]+1 == ans[row][column])
                    cout<<"L\n";
                else if(ans[row+1][column]+1 == ans[row][column])
                    cout<<"D\n";
                else if(ans[row][column+1]+1 == ans[row][column])
                    cout<<"R\n";
                else if(ans[row-1][column]+1 == ans[row][column])
                    cout<<"U\n";
            }
            else
                cout<<"?\n";
        }
        else cout<<"?\n";
    }
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    // revisa que el input tenga sentido,
    // si no arroja el error cin.failbit
    cin.exceptions(cin.failbit);

    //srand (time(nullptr));

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
5 5
...##
.E..#
#.X.#
...##
...#.
5
1 1
2 2
3 3
3 1
5 5
*/
