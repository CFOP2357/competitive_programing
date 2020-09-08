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

multiset<ull, greater<int>> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.insert(z);
    }

    b.push_back(*a.begin());
    a.erase(a.begin());
    int g = b.back();
    int sig;
    while(a.size()){
        sig = 1;
        for(int j : a){
            if(__gcd(j, g) > __gcd(sig, g))
                sig = j;
            else if(__gcd(j, g) == __gcd(sig, g) && j>sig)
                sig = j;
        }
        g = __gcd(g, sig);
        b.push_back(sig);
        a.erase(a.find(sig));
    }

    for(int ans : b)
        cout<<ans<<" ";
    cout<<"\n";
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

