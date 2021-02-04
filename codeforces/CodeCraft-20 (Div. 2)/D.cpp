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

#define MAX 1100
#define MOD 1000000007


ull n;

void solve(){

    cin>>n;

    vector<vector<char>> grid(n+2, vector<char>(n+2, '#'));
    vector<vector<pii>> whereEnds(n+2, vector<pii>(n+2, {0, 0}));

    queue<pii> nxt;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>whereEnds[i][j].first>>whereEnds[i][j].second; ///si da mal podria ser invertir esto
            if(i==whereEnds[i][j].first && j==whereEnds[i][j].second){
                nxt.push({i, j});
                grid[i][j]='X';
            }
        }

    while(nxt.size()){
        int i = nxt.front().first, j = nxt.front().second;
        nxt.pop();

        if(whereEnds[i][j].first == whereEnds[i][j+1].first && whereEnds[i][j].second == whereEnds[i][j+1].second && grid[i][j+1]=='#'){
            grid[i][j+1] = 'L';
            nxt.push({i, j+1});
        }
        if(whereEnds[i][j].first == whereEnds[i][j-1].first && whereEnds[i][j].second == whereEnds[i][j-1].second && grid[i][j-1]=='#'){
            grid[i][j-1] = 'R';
            nxt.push({i, j-1});
        }
        if(whereEnds[i][j].first == whereEnds[i+1][j].first && whereEnds[i][j].second == whereEnds[i+1][j].second && grid[i+1][j]=='#'){
            grid[i+1][j] = 'U';
            nxt.push({i+1, j});
        }
        if(whereEnds[i][j].first == whereEnds[i-1][j].first && whereEnds[i][j].second == whereEnds[i-1][j].second && grid[i-1][j]=='#'){
            grid[i-1][j] = 'D';
            nxt.push({i-1, j});
        }

    }


    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if(whereEnds[i][j].first == -1 && whereEnds[i][j].second == -1){

                if(whereEnds[i][j+1].first == -1 && whereEnds[i][j+1].second == -1){
                    grid[i][j]='R';
                    grid[i][j+1]='L';
                }

                if(whereEnds[i][j-1].first == -1 && whereEnds[i][j-1].second == -1){
                    grid[i][j]='L';
                    grid[i][j-1]='R';
                }

                if(whereEnds[i+1][j].first == -1 && whereEnds[i+1][j].second == -1){
                    grid[i][j]='D';
                    grid[i+1][j]='U';
                }

                if(whereEnds[i-1][j].first == -1 && whereEnds[i-1][j].second == -1){
                    grid[i][j]='U';
                    grid[i-1][j]='D';
                }

            }
        }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(grid[i][j] == '#'){
                cout<<"INVALID\n";
                return;
            }

    cout<<"VALID\n";

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout<<grid[i][j];
        cout<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

