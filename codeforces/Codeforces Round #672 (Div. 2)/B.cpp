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

#define MAX 100100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

int sz[MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    fill(sz, sz+n+5, 0);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        int j;
        for(j =0; z; j++, z/=2);
        sz[j]++;

    }

    ull ans=0;
    for(int i=0; i<n; i++){
        ull z = a[i];

        int j;
        for(j =0; z; j++, z/=2);
        sz[j]--;

        ans+=sz[j];
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

