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
vector<ull> c;
ull n;

void solve(){
    a.clear(); b.clear(); c.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        c.push_back(z);
    }

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    for(int i=0; i<n; i++)
        if(b[i]<a[i])
            swap(a[i], b[i]);

    ull ans = 0;
    ull acum = 2 + abs(b[1]-a[1]);

    for(int i = 1; i<n-1; i++){

        //cout<<c[i]<<" ";
        ans = max(ans, acum+c[i]-1);

        //cout<<ans<<" ";

        if(b[i+1]==a[i+1]){
            acum = 2;
        }
        else {
            acum += a[i+1] - 1 + (c[i]-b[i+1]);
            acum = max(acum, b[i+1]-a[i+1]);
            acum += 2;
        }
    } //cout<<"#\n";

    acum += c.back() -1;

    cout<<max(acum, ans)<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

