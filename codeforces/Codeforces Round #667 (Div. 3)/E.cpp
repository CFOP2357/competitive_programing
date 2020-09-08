#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

vector<ull> a;
vector<ull> b;
int l[MAX], r[MAX];
ull n, k;

void solve(){
    a.clear(); b.clear();
    cin>>n>>k;
    fill(l, l+n+5, 0);
    fill(r, r+n+5, 0);
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<n; i++){
        int z; cin>>z;
    }

    sort(a.begin(), a.end());

    for(int i = a.size()-1; i>=0; i--){
        int amount = (upper_bound(a.begin(), a.end(), a[i]+k) - a.begin()) - i;
        r[i] = max(r[i+1], amount);
    }

    for(int i = 0; i<a.size(); i++){
        int amount = i-(lower_bound(a.begin(), a.end(), a[i]-k) - a.begin()) + 1;
        if(i>0)
            l[i] = max(l[i-1], amount);
        else l[i] = amount;
    }

    int ans = 0;
    for(int i = 0; i<a.size(); i++){
        int amount = (upper_bound(a.begin(), a.end(), a[i]+k) - a.begin()) - i;
        ans = max(ans, amount);
        if(i+amount < a.size())
            ans = max(ans, amount + r[i+amount]);
        if(i-1 >= 0)
            ans = max(ans, amount + l[i-1]);
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

/*
1
1 1
1000000000
1000000000

1
10 10
15 19 8 17 20 10 9 2 10 19
12 13 6 17 1 14 7 9 19 3
*/
