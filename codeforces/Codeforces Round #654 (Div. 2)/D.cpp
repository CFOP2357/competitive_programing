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

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 500
#define MOD 1000000007

ull n, k;
bool grid[MAX][MAX];

void solve(){
    cin>>n>>k;
    if(k%n)
        cout<<"2\n";
    else cout<<"0\n";

    //cout<<sz<<"\n";

    for(int i=0; i<n; i++)
        fill(grid[i], grid[i]+n+1, 0);


    int j = 0, f = 0;
    for(int i=0; k--; i = (i+1)%n){
        grid[i][(j+f)%n] = 1;

        if(++j == n){
            j=0;
            f++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout<<grid[i][j];
        cout<<"\n";
    }


}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

