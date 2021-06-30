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

#define MAX 1000100
#define MOD 1000000007

ull gauss(ull n){
    return (n*(n+1))/2;
}

ull bs(ull d, ull l=0, ull r=MOD){ //(l, r]
    if(l+1>=r)
        return r;
    ull m = (l+r)/2;
    if(gauss(m)>=d)
        return bs(d, l, m);
    return bs(d, m, r);
}

void solve(){
    ull a, b; cin>>a>>b;
    ull d = abs(a-b);


    if(d){
        ull ans = bs(d);
        while((gauss(ans)-d)%2){
            ans++;
        }
        cout<<ans<<"\n";
    }
    else
        cout<<"0\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

