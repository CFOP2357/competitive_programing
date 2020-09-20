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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    sort(all(a));
    //cout<<"#";
    int i=0, j=n/2;
    bool p = true;
    while(j<n || i<n/2){
        if(p)
            b.push_back(a[j++]);
        else b.push_back(a[i++]);
        p=!p;
    }

    int ans = 0;
    for(int i=1; i<n-1; i+=2){
        if(b[i-1]>b[i] && b[i+1]>b[i])
            ans++;
    }

    cout<<ans<<"\n";
    for(int k : b)
        cout<<k<<" ";
    cout<<"\n";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}


