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
ull n, k;

void solve(){
    a.clear(); b.clear();
    cin>>n>>k;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<k; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    sort(a.begin(), a.end(), greater<ull>());
    sort(b.begin(), b.end());

    ull ans = 0;
    int i=0, j=n-1;
    for(ull &w : b){
        if(w==1){
            ans += 2*a[i++];
        }
        else {
            ans += a[i++];
        }
        w--;
    }

    sort(b.begin(), b.end(), greater<ull>());
    for(int w : b){
        if(w){
            ans += a[j--];
            j -= w-1;
        }
    }

    cout<<ans<<"\n";
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

