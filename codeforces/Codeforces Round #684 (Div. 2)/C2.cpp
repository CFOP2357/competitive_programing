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

inline void change(int y, int x){
    y--, x--;
    //grid[y][x] = 'x';
    grid[y][x] = (grid[y][x]=='0')?'1':'0';
}

bool zero(){
    for(int i=n-2; i<n; i++)
        for(int j=m-2; j<m; j++)
            if(grid[i][j]=='1')
                return false;
    return true;
}

vector<vector<pii>> ans;
bool bsk(int t = 0){
    if(zero())
        return true;
    if(t>=4)
        return false;

    ans.push_back( vector<pii>( { {n, m},{n, m-1},{n-1, m}  } ) );
    change(n, m);
    change(n, m-1);
    change(n-1, m);
    if(bsk(t+1))
        return true;
    change(n, m);
    change(n, m-1);
    change(n-1, m);
    ans.pop_back();

    ans.push_back( vector<pii>( { {n, m},{n, m-1},{n-1, m-1}  } ) );
    change(n, m);
    change(n, m-1);
    change(n-1, m-1);
    if(bsk(t+1))
        return true;
    change(n, m);
    change(n, m-1);
    change(n-1, m-1);
    ans.pop_back();

    ans.push_back( vector<pii>( { {n, m},{n-1, m},{n-1, m-1}  } ) );
    change(n, m);
    change(n-1, m);
    change(n-1, m-1);
    if(bsk(t+1))
        return true;
    change(n, m);
    change(n-1, m);
    change(n-1, m-1);
    ans.pop_back();

    ans.push_back( vector<pii>( { {n-1, m-1},{n, m-1},{n-1, m}  } ) );
    change(n-1, m-1);
    change(n, m-1);
    change(n-1, m);
    if(bsk(t+1))
        return true;
    change(n-1, m-1);
    change(n, m-1);
    change(n-1, m);
    ans.pop_back();

    return false;
}

void solve(){
    grid.clear();

    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        grid.push_back(s);
    }

    ans.clear();
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m; j++){
            if(i>=n-2 && j>=m-2) continue;

            if(grid[i][j]=='1'){

                //cout<<"\n\n";
                //cout<<i<<" "<<j<<"\n";

                if(j<m-1){
                    ans.push_back( vector<pii>( { {i+1, j+1},{i+1, j+2},{i+2, j+1}  } ) );
                    change(i+1, j+1);
                    change(i+1, j+2);
                    change(i+2, j+1);
                }
                else{
                    ans.push_back( vector<pii>( { {i+1, j+1},{i+2, j},{i+2, j+1}  } ) );
                    change(i+1, j+1);
                    change(i+2, j);
                    change(i+2, j+1);
                }

                /*for(int i=0; i<n; i++){
                    for(int j = 0; j<m; j++)
                        cout<<grid[i][j];
                    cout<<"\n";
                }*/
            }

        }
    }

    for(int i=0; i<m-2; i++) {
        if(grid[n-2][i]=='1'){
            ans.push_back( vector<pii>( { {n-1, i+1},{n-1, i+2},{n, i+1}  } ) );
            change(n-1, i+1);
            change(n-1, i+2);
            change(n, i+1);
        }
        if(grid[n-1][i]=='1'){
            ans.push_back( vector<pii>( { {n, i+1},{n, i+2},{n-1, i+2}  } ) );
            change(n, i+1);
            change(n, i+2);
            change(n-1, i+2);
        }
    }

    bsk();
    /*cout<<"\n\n";
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++)
            cout<<grid[i][j];
        cout<<"\n";
    }*/


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

/*
1
2 2
10
11

1
3 3
011
101
110

1
5 5
01011
11001
00010
11011
10000
*/
