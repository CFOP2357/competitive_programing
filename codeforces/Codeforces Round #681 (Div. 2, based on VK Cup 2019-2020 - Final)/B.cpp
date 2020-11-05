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

ull a, b;

void solve(){
    cin>>a>>b;
    string s; cin>>s;

    int i;
    for(i=0; i<s.size() && s[i]=='0'; i++);

    ull zero = 0;
    ull ans = 0;

    if(i<s.size())
        ans = a;

    for(;i<s.size(); i++){

        //cout<<zero<<"\n";

        if(s[i]=='1'){
            ans += min(a, zero);
            zero = 0;
        }
        else zero += b;

    }

    cout<<ans<<"\n";

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
5 1
01101110
*/
