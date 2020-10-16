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

ull n, m,a, b;

void solve(){
    cin>>n>>m>>a>>b;

    if(a*n != b*m){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";


    vector<vector<bool>> grid(n, vector<bool>(m, 0));
    for(int i=0, k = 0; i<n; i++, k+=a){
        for(int j=0; j<a; j++){
            grid[i][(j+k)%m] = true;
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

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
3 4 4 3
*/
