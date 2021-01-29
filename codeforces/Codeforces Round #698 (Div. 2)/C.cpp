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

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    //cout<<"############\n";
    a.clear();

    cin>>n;
    for(int i=0; i<2*n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    sort(all(a), greater<ull>());

    ull k = n;
    ull last = 0;
    for(int i=0; i<2*n; i+=2, k--){
        //cout<<a[i]<<" "<<last<<"\n";
        ull x = a[i] - 2*last;

        if(x<=0 || x % (k*2)){
            cout<<"NO\n";
            return;
        }

        last += x/(k*2);
    }

    cout<<"YES\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

