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

typedef unsigned long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

ull u, v;

void solve(){
    cin>>u>>v;

    if(u>v || u%2 != v%2){
        cout<<"-1\n";
        return;
    }

    vector<ull> ans(3);

    ans[0] = u;
    v -= u;
    if( !(u%2) && (v%2) )
    {
        cout<<"-1\n";
        return;
    }
    for(ull p=1; p<=v || p<=u;p*=2){

            if( !(!(u&p) && !(v&p)) ){
                ull k = p/2;
                if(u&k){
                    ans[1]+=k;
                    ans[2]+=k;
                }
                else {
                    ans[1]+=k;
                    ans[0]+=k;
                }
            }

    }

    int sz = 0;
    while(sz<3 && ans[sz])sz++;

    cout<<sz<<"\n";
    for(int i=0; i<sz; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

