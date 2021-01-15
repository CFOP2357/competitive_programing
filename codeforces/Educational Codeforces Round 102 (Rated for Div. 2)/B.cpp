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

/*
1
aba
ab
*/

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    string s, t;
    cin>>s;
    cin>>t;

    if(t.size()>s.size())
        swap(t, s);

    int lcmSize = (t.size()*s.size())/__gcd(t.size(), s.size());

    string ans = "";
    for(int i=0; i<lcmSize/s.size(); i++)
        ans += s;

    for(int i=0; i<lcmSize; i++){
        if(ans[i]!=t[i%t.size()]){
            cout<<"-1\n";
            return;
        }
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

