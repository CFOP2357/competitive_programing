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

ull a, m;
string s;

void solve(){
    cin>>a>>m;

    set<ull> primes;

    ull G = __gcd(a, m);

    ull d = m;
    for(ull i=2; i*i<=m; i++){
        if(!(d%i)){
            if(G%i)
                primes.insert(i);

            ull p = 1;
            while(!(d%i)){
                d/=i;
                if(!(G%p))
                    p*=i;
            }

            if(!(G%i) && G%p)
                primes.insert(p);
        }
    }
    if(d>1 && G%d)
        primes.insert(d);


    ull ans = m/G;

    for(ull prime : primes){

        ull lcm = (prime*G)/__gcd(prime, G);

        if((a - a%prime) + lcm < a+m){
            ans--;

            ans -= (m - (((a - a%prime) + lcm) - a) - 1)/lcm;
        }

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

