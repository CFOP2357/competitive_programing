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
ull n, l, r;

void solve(){

    cin>>n>>l>>r;

    ull i = 1;
    ull j;
    for(j = 1; i + (2*max(n-j, (ull)1)) <= l; j++)
        i += (2*max(n-j, (ull)1));

    //cout<<i<<" "<<j<<"\n";

    for(;i<=r; j++){
        ull a = j+1;
        for(ull k = 0; a<=n; k++){
            if(i+k >= l && i+k<=r)
                if(k%2)
                    cout<<a<<" ";
                else cout<<j<<" ";
            if(k%2)
                a++;
        }


         i += (2*max(n-j, (ull)1));
         //cout<<i<<"$\n";
         //while(true);
    }

    if(r == n*(n-1)+1)
        cout<<1;

    cout<<"\n";

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
2 1 3
*/
