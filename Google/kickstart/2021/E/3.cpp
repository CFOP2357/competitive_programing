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
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 2000
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;
ll ans;

char grid[MAX][MAX];
bool visited[MAX][MAX];
int opx[MAX][MAX];
int opy[MAX][MAX];

void run(int i, int j, char c){
    if(visited[i][j])
        return;
    visited[i][j] = true;

    if(grid[i][j] != c)
        ans++;
    grid[i][j] = c;

    run(i, opx[i][j], c);
    run(opy[i][j], j, c);
}

void solve(){
    ans = 0;

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++){
        int sz = 0;
        for(int j=0; j<m; j++){
            if(grid[i][j] == '#'){
                sz = 0;
                continue;
            }
            sz++;

            if(j == m-1 or grid[i][j+1] == '#'){
                int l = j-sz+1;
                int r = j;
                while(l <= r){
                    opx[i][l] = r;
                    opx[i][r] = l;

                    r--;
                    l++;
                }
            }
        }
    }


    for(int j=0; j<m; j++){
        int sz = 0;
        for(int i=0; i<n; i++){
            if(grid[i][j] == '#'){
                sz = 0;
                continue;
            }
            else
                sz++;

            if(i == n-1 or grid[i+1][j] == '#'){
                int l = i-sz+1;
                int r = i;
                while(l <= r){
                    opy[l][j] = r;
                    opy[r][j] = l;

                    r--;
                    l++;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j] != '.' and grid[i][j] != '#')
                run(i, j, grid[i][j]);

    cout<<ans<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<grid[i][j];
        cout<<"\n";
    }
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
2 2
A.
.#

*/
