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

#define MAX 20001000
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, c, d, x;
string s;

ull D[MAX];

vector<ull> dd;
ull ans;

void test_(int i=0, ull G = 1){

    if(i==dd.size()){

        ull L = x + d*G;

        if(L%c)
            return;

        L/=c;

        if(L%G)
            return;

        L/=G;

        map<ull, ull> DD;

        ull sz = 0;
        while(L>1){
            sz++;
            DD[D[L]]++;
            L /= D[L];
        }

        cout<<G<<" "<<sz<<"\n";

        ull aa = 1;
        for(auto v : DD){
            aa *= v.second+1;
        }

        ans += pow(DD.size(), 2);

        return;
    }

    test_(i+1, G*dd[i]);
    test_(i+1, G);

}

void solve(){

    dd.clear();

    cin>>c>>d>>x;

    ull k = x;
    while(k>1){
        dd.push_back(D[k]);
        k/=D[k];
    }

    ans = 0;
    test_();

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
*/
