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


ull n;
ull ans;

bool valid(ull d){
    vector<bool> selected(10, false);

    ull k = d;
    while(k){
        selected[k%10]=true;
        k/=10;
    }


    for(int i=2; i<10; i++){
        if(selected[i] && d%i)
            return false;
    }

    return true;

}

void f(ull i=2, ull value = 1){
    if(i==10){

        ull d = n;
        if(n%value)
            d += value - n%value;

        for(int i=0; i<100; i++){
            if(valid(d)){
                ans = min(d, ans);
                return;
            }
            if(d>n+362880)
                return;
            d+=value;
        }

        return;

    }

    f(i+1, value*i);
    f(i+1, value);


}

void solve(){

    cin>>n;
    ans = LLONG_MAX;

    f();

    cout<<ans<<"\n";

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
1234567890
*/
