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

vector<ull> k;
vector<ull> c;
ull n, m;

void solve(){ //el mas caro agarra el regalo mas barato a su izquierda
    k.clear(); c.clear();


    cin>>n>>m;

    vector<ull> _times(m, 0);

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        k.push_back(z);
        _times[z-1]++;
    }

    for(int i=0; i<m; i++){
        ull z; cin>>z;
        c.push_back(z);
    }

    ull ans = 0;
    int j = 0;
    for(int i=m-1; i>=0; i--){
        while(j<i && _times[i]){
           _times[i]--;
           ans += c[j++];
        }
        ans += c[i]*_times[i];
    }

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

