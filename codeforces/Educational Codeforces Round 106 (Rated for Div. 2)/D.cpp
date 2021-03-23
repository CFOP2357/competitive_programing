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

typedef int ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 20001000
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, c, d, x;
string s;

ull D[MAX];
ull numberPrimes[MAX];

ull ans;

void test_(ull G){

    ull L = x/G + d;

    if(L%c)
        return;

    L/=c;

    ull sz = numberPrimes[L];

    ans += pow(2, sz);
}

void solve(){

    cin>>c>>d>>x;

    ans = 0;

    ull i;
    for(i=1; i*i<x; i++){
        if(!(x%i)){
            test_(i);
            test_(x/i);
        }
    }

    if(i*i==x)
        test_(i);

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    for(ull i=2; i<MAX; i++){
        if(D[i])
            continue;
        for(ull j=i; j<MAX; j+=i){
            D[j]=i;
            numberPrimes[j]++;
        }
    }


    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
4 2 6

1
1 1 3

1
2 7 25
*/
