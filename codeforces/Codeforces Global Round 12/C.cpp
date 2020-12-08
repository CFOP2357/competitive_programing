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

#define MAX 500
#define MOD 1000000007

ull n;

char grid[MAX][MAX];

void solve(){

    cin>>n;
    int d[3] = {0, 0, 0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='X')
                d[(i+j)%3]++;
        }
    }

    int toChange = 0;
    for(int i=0; i<3; i++)
        if(d[i]<d[toChange])
            toChange=i;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //cout<<(i+j)%3<<" ";
            if(grid[i][j]=='X' && toChange == (i+j)%3){
                grid[i][j]='O';
            }
        } //cout<<"\n";
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
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

