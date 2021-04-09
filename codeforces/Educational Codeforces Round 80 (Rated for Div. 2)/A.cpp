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
ull n, m, d;
string s;

ull divCeil(ull a, ull b){
    if(a%b)
        a+=b;
    return a/b;
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>d;

    ull x = 0;
    while((1<<x)<n){

        if(divCeil(d, (1<<x) + 1) + (1<<x) <= n ){
            cout<<"YES\n";
            return;
        }

         x++;
    }

    for(x=0; x<=100000; x++){

        if(divCeil(d, x+1)+x<=n){
            cout<<"YES\n";
            return;
        }

    }

    cout<<"NO\n";

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

