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

ull a, b, k;

void solve(){
    cin>>a>>b>>k;

    if( (k && k >= a+b-1) || (!a && k) || (b==1 && k)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    string ans(b, '1');
    ans += string(a, '0');

    cout<<ans<<"\n";

    ans[b-1] = '0';
    ans[b-1+min(a, k)] = '1';

    if(k>a){
        ans[b-1] = '1';
        ans[b-1-(k-a)] = '0';
    }

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

