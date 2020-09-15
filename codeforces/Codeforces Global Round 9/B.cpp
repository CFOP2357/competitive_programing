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

vector<ull> a;
vector<ull> b;
ull n, m;

int grid[MAX][MAX];

void solve(){

    cin>>n>>m;
    for(int i =0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];

    bool posible = true;
    for(int i =1; i<n-1; i++)
        for(int j=1; j<m-1; j++)
            if(grid[i][j]>4) posible = false;

    for(int i =1; i<n-1; i++){
        if(grid[i][0]>3) posible = false;
        if(grid[i][m-1]>3) posible = false;
    }

    for(int i =1; i<m-1; i++){
        if(grid[0][i]>3) posible = false;
        if(grid[n-1][i]>3) posible = false;
    }

    if(grid[0][0]>2 || grid[n-1][0]>2 || grid[n-1][m-1]>2 || grid[0][m-1]>2) posible = false;

    if(posible){
        cout<<"YES\n";

        cout<<"2 ";
        for(int i=1; i<m-1; i++)
            cout<<"3 ";
        cout<<"2\n";

        for(int i=1; i<n-1; i++){
            cout<<"3 ";
            for(int j=1; j<m-1; j++)
                cout<<"4 ";
            cout<<"3\n";
        }

        cout<<"2 ";
        for(int i=1; i<m-1; i++)
            cout<<"3 ";
        cout<<"2\n";
    }
    else cout<<"NO\n";


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

