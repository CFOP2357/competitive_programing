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

#define MAX 1000100
#define MOD 1000000007

ull n, m;
vector<string> grid;

void solve(){
    grid.clear();

    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        grid.push_back(s);
    }

    vector<vector<pii>> ans;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){

            if(grid[i][j]=='1'){
                ans.push_back( vector<pii>( { {i+1, j+1},{i+1, j+2},{i+2, j+1}  } ) );
                ans.push_back( vector<pii>( { {i+1, j+1},{i+1, j+2},{i+2, j+2}  } ) );
                ans.push_back( vector<pii>( { {i+1, j+1},{i+2, j+2},{i+2, j+1}  } ) );
            }

        }
    }

    for(int i=0; i<n-1; i++){
        if(grid[i][m-1]=='1'){
            ans.push_back( vector<pii>( { {i+1, m},{i+1, m-1},{i+2, m}  } ) );
            ans.push_back( vector<pii>( { {i+1, m},{i+1, m-1},{i+2, m-1}  } ) );
            ans.push_back( vector<pii>( { {i+1, m},{i+2, m},{i+2, m-1}  } ) );
        }
    }

    for(int i=0; i<m-1; i++){
        if(grid[n-1][i]=='1'){
            ans.push_back( vector<pii>( { {n, i+1},{n, i+2},{n-1, i+1}  } ) );
            ans.push_back( vector<pii>( { {n, i+1},{n, i+2},{n-1, i+2}  } ) );
            ans.push_back( vector<pii>( { {n, i+1},{n-1, i+2},{n-1, i+1}  } ) );
        }
    }

    if(grid[n-1][m-1]=='1'){
        ans.push_back( vector<pii>( { {n, m},{n, m-1},{n-1, m}  } ) );
        ans.push_back( vector<pii>( { {n, m},{n, m-1},{n-1, m-1}  } ) );
        ans.push_back( vector<pii>( { {n, m},{n-1, m-1},{n-1, m}  } ) );
    }


    cout<<ans.size()<<"\n";
    for(auto a : ans){
        for(auto p : a)
            cout<<p.first<<" "<<p.second<<" ";
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

