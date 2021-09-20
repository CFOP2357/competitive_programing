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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    cin>>s;

    vector<ll> left(n, INT_MIN);
    vector<ll> right(n, INT_MAX);

    if(s[0] == '1')
        left[0] = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            left[i] = i;
        }
        else {
            left[i] = left[i-1];
        }
    }

    if(s.back() == '1')
        right.back() = n-1;
    for(int i = n-2; i >= 0; i--){
        if(s[i] == '1'){
            right[i] = i;
        }
        else {
            right[i] = right[i+1];
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++)
        ans += min(abs(i - left[i]), abs(i - right[i]));

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


