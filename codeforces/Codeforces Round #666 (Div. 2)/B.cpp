#include <bits/stdc++.h>
using namespace std;

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
ull n;

#define MAX 100005

ull cost(ull m){
    ull p = 1;
    ull ans = 0;
    for(int i = 0; i<n; i++){
        ans += abs(p-a[i]);
        p*=m;
        //cout<<ans<<"\n";
    }
    return ans;
}

ull bS(){
    ull maxi= min((long long)MAX, (long long)pow(LLONG_MAX, (double)1/(double)(n-1)));
    //cout<<maxi<<"\n";
    ull m = 1;
    for(int i = 1; i<maxi; i++){
        if(cost(m) > cost(i)){
            m = i;
        }
    }
    return m;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    sort(a.begin(), a.end());

    ull m = bS();
    ull p = 1;
    ull ans = 0;
    for(ull k : a){
        ans += abs(k-p);
        p*=m;
    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    //cout<<cost(2);
    return 0;
}

