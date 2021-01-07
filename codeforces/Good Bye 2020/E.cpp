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

typedef unsigned long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 500010
#define MOD 1000000007

vector<ull> a;
vector<ull> b;

ull P[MAX][61];

ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;

    vector<ull> appears(70, 0);
    vector<ull> notAppears(70, 0);

    ull sum = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        sum += z;
        sum %= MOD;

        ull p = 1;
        for(int d = 0; d<61; d++, p*=2){

            if(z&p)
                appears[d]++;
            else notAppears[d]++;

        }

    }

    ull ans = 0;

    for(int j = 0; j<n; j++){

        ull z = a[j];

        ull ansAnd = 0;
        ull p = 1;
        for(int d = 0; d<61; d++, p*=2){
            if(z&p){
                ansAnd += P[appears[d]][d];
                ansAnd %= MOD;
            }
        }

        ull ansOr = sum;
        p = 1;
        for(int d = 0; d<61; d++, p*=2){
            if(z&p){
                ansOr += P[notAppears[d]][d];
                ansOr %= MOD;
            }
        }

        ans += (ansOr * ansAnd)%MOD;
        ans %= MOD;

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ull p = 1;
    for(int d = 0; d<61; d++, p*=2)
        for(ull v = 1; v<MAX; v++){
            P[v][d] = P[v-1][d] + p;
            P[v][d] %= MOD;
        }

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

