#include <bits/stdc++.h>

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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 200010
#define MOD 1000000007

ull n, m;
string s;

void solve(){
    cin>>n;

    ull p = 1;

    //cout<<p<<"%\n";

    set<ull> ans;
    for(ull i=1; i<n; i++){

        if(__gcd(n, i) != 1)
            continue;
        p*=i;
        p%=n;
        ans.insert(i);
    }

    //cout<<p<<"&\n";

    ull k = p%n;
    //cout<<k<<"\n";

    k = p%n;
    if(__gcd(k, n)!=1){
        cout<<"1\n";
        cout<<"1\n";
        return;
    }

    if(k>1){
        assert(ans.find(k)!=ans.end());
        ans.erase(k);
    }

    cout<<ans.size()<<"\n";

    for(auto a : ans)
        cout<<a<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

