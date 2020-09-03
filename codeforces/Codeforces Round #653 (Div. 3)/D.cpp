#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define findOrd find_by_order
#define findkwy order_of_key
*/

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> b;

void solve(){
    int n, k; cin>>n>>k;
    map<ull, ull> cong; // congruencia, cantidad

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        if(z%k)
            cong[k - z%k]++;
    }

    long long ans = 0;
    for(auto c : cong){
        ans = max(ans, c.first + k*(c.second-1) + 1);
    }

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}

