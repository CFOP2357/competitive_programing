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

vector<ull> a;
vector<ull> b;
ull A, B, C, D;

bool posible(ull x, ull y){
    return x+y>C;
}

ull bS(ull x, ull l, ull r){ ///0000000000000000000111111111111111
    //cout<<l<<" "<<r<<"\n";
    if(l+1>=r)
        return r;

    ull m  = (l+r)/2;

    if(posible(x, m))
        return bS(x, l, m);
    return bS(x, m, r);
}

ull gauss(ull n){
    return (n*(n+1))/2;
}

void solve(){
    cin>>A>>B>>C>>D;

    ull ans = 0;

    for(ull x = A; x<=B; x++){
        ull y = bS(x, B-1, C);

        ull tmp = 0;

        if(x+y<=C)
            continue;

        ull z = min(x+y-1, D);
        tmp += (C-y+1)*(z-C+1);

        ull n = min(C-y, D-z);
        tmp += gauss(n);

        if(D-z < C-y)
            tmp += (D-z)*((C-y)-(D-z));

        //cout<<x<<" "<<y<<" "<<z<<" "<<tmp<<"\n";

        ans +=tmp;
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

/*
1 6 10 15

10 10 13 14

3 3 6 6
*/
