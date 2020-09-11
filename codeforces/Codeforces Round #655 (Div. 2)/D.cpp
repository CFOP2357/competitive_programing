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

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 200100
#define MOD 1000000007

ull l[MAX];
ull r[MAX];
vector <ull> a;

void solve(){
    a.clear();
    ull n;
    cin>>n;

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    l[0] = a[0];
    if(n>1)l[1] = a[1];
    for(int i=2; i<n; i++)
        l[i] = a[i] + l[i-2];

    for(int i=n-1; i>=0; i--)
        r[i] = a[i] + r[i+2];

    ull ans = max(r[0], r[1]);
    for(int i = 0; i <= n+2; i++)
        ans = max (ans, l[i] + r[i+1]);

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

