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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, x;

ull gauss(int n){
    return (n*(n+1))/2;
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>x;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    a.push_back(0);
    for(int k : b)
        a.push_back(k);
    for(int k : b)
        a.push_back(k);

    vector<int> acum;
    acum.push_back(0);
    vector<int> sum;
    sum.push_back(0);

    for(int i=1; i<a.size(); i++)
        acum.push_back(a[i]+acum.back());

    for(int i=1; i<a.size(); i++)
        sum.push_back(gauss(a[i])+sum.back());


    ull ans = 0;
    for(int i=1; i<=n; i++){
        int nxt = lower_bound(all(acum), acum[i-1]+x) - acum.begin();

        ull total = sum[nxt-1] - sum[i];
        int x = ::x - (acum[nxt-1]-acum[i]);

        if(nxt == i)
            total = 0, x = ::x;

        if(i==nxt)
            total = gauss(a[i]) - gauss(a[i]-x);
        else if(a[i] >= a[nxt])
            total += gauss(a[i]) + gauss(x-a[i]);
        else{
            total += gauss(min(a[nxt], (ull)(x-1)));
            x -= min(a[nxt], (ull)(x-1));
            total += gauss(a[i]) - gauss(a[i]-x);
        }

        ans = max(total, ans);

        //cout<<i<<" "<<total<<"\n";

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

