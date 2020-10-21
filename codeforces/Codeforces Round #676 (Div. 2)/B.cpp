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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

vector<string> grid;

void solve(){
    grid.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        grid.push_back(s);
    }

    if(grid[0][1] == grid[1][0] && grid[0][1] != grid[n-1][n-2] && grid[n-1][n-2] == grid[n-2][n-1]){
        cout<<"0\n";
        return;
    }
    if(grid[0][1] == grid[1][0] && grid[0][1] == grid[n-1][n-2] && grid[0][1] == grid[n-2][n-1]){
        cout<<"2\n";
        cout<<"1 2\n";
        cout<<"2 1\n";
        return;
    }
    if(grid[n-1][n-2] == grid[n-2][n-1]){
        cout<<"1\n";
        if(grid[0][1] == grid[n-1][n-2])
            cout<<"1 2\n";
        else
            cout<<"2 1\n";
        return;
    }
    if(grid[0][1] == grid[1][0]){
        cout<<"1\n";
        if(grid[0][1] == grid[n-1][n-2])
            cout<<n<<" "<<n-1<<"\n";
        else
            cout<<n-1<<" "<<n<<"\n";
        return;
    }

    cout<<"2\n";

    if(grid[0][1] == '1')
        cout<<"1 2\n";
    else
        cout<<"2 1\n";

    if(grid[n-1][n-2] == '0')
        cout<<n<<" "<<n-1<<"\n";
    else
        cout<<n-1<<" "<<n<<"\n";

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
5
3
S10
101
11F
3
S00
101
11F
3
S10
100
11F
3
S00
001
11F
3
S00
101
10F

4
3
S00
101
10F
3
S10
001
10F
3
S00
100
11F
3
S10
000
11F
*/
