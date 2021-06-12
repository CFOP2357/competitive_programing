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

#include <time.h>

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

vector<long double> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    long double sum = 0;
    for(int i=0; i<n; i++){
        long double z; cin>>z;
        a.push_back(z);
    }
    sort(all(a));

    long double p = 1;
    for(int i=0; i<n; i++, p*=2.0){
        sum += p*a[i];
    }

    long double ans = sum/p;
    cout<<ans<<"\n";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));
    cout.precision(100000);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

