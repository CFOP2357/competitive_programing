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

ull n, m, k;

void solve(){

    cin>>n>>m;
    cin>>k;

    string ans;

    for(int i=0; i<2*k; i++){ int x, y; cin>>x>>y;}

    for(int i=0; i<n; i++) ans.push_back('U');
    for(int i=0; i<m; i++) ans.push_back('L');


    char mv = 'R';
    for(int i=0; i<n; i++, mv = (mv=='L')?'R':'L'){
        for(int j=0; j<m-1; j++)
            ans.push_back(mv);
        if(i<n-1)ans.push_back('D');;
    }

    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

