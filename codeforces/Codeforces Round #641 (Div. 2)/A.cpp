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

#define MAX 1000001
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, k;

ull d[MAX];

void solve(){

    cin>>n>>k;

    //cout<<d[n]<<"\n";

    ull d =n;
    for(ull i = 2; i*i<=n; i++){
        if(n%i == 0){
            d = i;
            break;
        }
    }

    n += d;
    k--;

    cout<<n+k*2<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    /*for(int i = 2; i<MAX; i++){
        if(d[i]) continue;
        d[i] = i;
        for(int j = i*i; j<MAX; j+=i){
            if(d[i]) continue;
            d[j] = i;
        }
    }*/

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

