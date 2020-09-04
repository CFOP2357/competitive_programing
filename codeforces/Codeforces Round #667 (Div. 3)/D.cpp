#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef unsigned long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

vector<ull> a;
vector<ull> b;
ull n;

ull sum(ull n){
    ull ans = 0;
    for(; n; n/=10)
        ans += n%10;
    return ans;
}

ull bs(ull s, ull n){
    if(sum(n)<=s) return 0;
    return 10*bs(s, n/10 +1) + 10 - n%10;
}

void solve(){
    cin>>n;
    int s; cin>>s;
    cout<<bs(s, n)<<"\n";
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
1
2 1
*/
