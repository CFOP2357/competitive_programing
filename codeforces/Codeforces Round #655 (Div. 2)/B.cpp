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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;

    ull min_lcm = LLONG_MAX;
    ull a, b;

    if(n%2 == 0){
        min_lcm = n/2;
        a = n/2, b = n/2;
    }

    for(ull i=n/2; i>=0; i--){
        ull j = n-i;

        //cout<<i<<" "<<j<<" "<<__gcd(i, j)<<"\n";
        ull lcm = (i*j)/__gcd(i, j);
        //cout<<i<<" "<<j<<" "<<lcm<<"\n";
        if(lcm<min_lcm){
            min_lcm = lcm;
            a = i;
            b = j;
        }

        if(j%i == 0){
            a = i, b = j;
            break;
        }
    }

    cout<<a<<" "<<b<<"\n";


}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

