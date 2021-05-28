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

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

vector<ull> P{11, 111, 11111, 1111111};
void solve(){
    a.clear(); b.clear();
    cin>>n;

    for(ull i=0; i<=10; i++){
        for(ull j=0; j<=10; j++){
            for(ull k=0; k<=10; k++)
                for(ull l=0; l<=10; l++){
                    ull d = n - P[0]*i - P[1]*j - P[2]*k - P[3]*l;
                    if( d>=0 && (!(d%P[0]) or !(d%P[1]) or !(d%P[2]) or !(d%P[3])) ){
                        cout<<"YES\n";
                        return;
                    }
                }
        }
    }

    cout<<"NO\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));


    //cout<<__gcd(0,__gcd(0,__gcd(11, 111)));
    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

