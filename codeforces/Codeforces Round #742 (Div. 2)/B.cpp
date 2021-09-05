//#include <bits/stdc++.h>
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

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 300010
#define MOD 1000000007

int prefix_xor[MAX];

void solve(){
    int a, b;
    cin>>a>>b;

    int ans = a;
    int current_xor = prefix_xor[a-1];

    if(current_xor == b){
        cout<<ans<<"\n";
        return;
    }

    int xor_complement = (current_xor^b);
    ans++;

    if(xor_complement == a)
        ans++;

    cout<<ans<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    for(int i=1; i<MAX; i++)
        prefix_xor[i] = (prefix_xor[i-1]^i);

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

