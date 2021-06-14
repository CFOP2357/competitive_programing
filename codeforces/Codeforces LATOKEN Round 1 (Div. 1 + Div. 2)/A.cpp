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

#define MAX 100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

char grid[MAX][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    bool current = true;
    bool R_place = true;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            if(s[j] == 'R')
                R_place = current;
            else if(s[j]=='W')
                R_place = !current;
            grid[i][j] = s[j];
            current = !current;
        }
        if(!(m%2))
            current = !current;
    }

    current = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'R'){
                if(R_place != current){
                    cout<<"NO\n";
                    return;
                }
            }
            else if(grid[i][j]=='W'){
                if(R_place == current){
                    cout<<"NO\n";
                    return;
                }
            }
            else {
                if(R_place == current)
                    grid[i][j] = 'R';
                else
                    grid[i][j] = 'W';
            }
            current = !current;
        }
        if(!(m%2))
            current = !current;
    }

    cout<<"YES\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<grid[i][j];
        cout<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

