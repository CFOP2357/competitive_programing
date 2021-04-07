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
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, q;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>q;


    vector<vector<bool>> grid(3, vector<bool>(n+3, false));


    ull blocked = 0;
    while(q--){

        ull r, c; cin>>r>>c;

        grid[r][c] = !grid[r][c];
        bool add = grid[r][c];

        r--;
        if(!r) r = 2;


        if(add)
            blocked += grid[r][c-1] + grid[r][c] + grid[r][c+1];
        else
            blocked -= grid[r][c-1] + grid[r][c] + grid[r][c+1];

        if(!blocked)
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

