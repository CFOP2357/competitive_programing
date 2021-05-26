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

#define MAX 5010
#define MOD 1000000007

vector<ull> occupied;
vector<ull> not_occupied;
ull n, m;
string s;

ull dp[MAX][MAX];

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        if(z)
            occupied.push_back(i);
        else
            not_occupied.push_back(i);
    }

    for(ull i=1; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = INT_MAX;

    for(int i=0; i<occupied.size(); i++)
        for(int j=0; j<not_occupied.size(); j++){
            if(j>0)
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(occupied[i]-not_occupied[j]));
        }

    cout<<*min_element(dp[occupied.size()], dp[occupied.size()]+not_occupied.size()+1)<<"\n";
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

