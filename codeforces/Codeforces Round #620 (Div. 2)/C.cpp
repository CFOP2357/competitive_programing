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


ull n, m;
string s;

vector<ull> T, L, H;

void solve(){

    T.clear(); L.clear(); H.clear();

    cin>>n>>m;
    ull minTemp = m, maxTemp = m;

    for(int i=0; i<n; i++){
        ull t, l, h; cin>>t>>l>>h;
        T.push_back(t);
        L.push_back(l);
        H.push_back(h);
    }


    ull lastT = 0;
    for(int i=0; i<n; i++){
        ull t, l, h; t=T[i], l=L[i], h=H[i];

        ull D = t-lastT;

        minTemp -= D;
        maxTemp += D;

        if(l > maxTemp || h < minTemp ){
            cout<<"NO\n";
            return;
        }

        maxTemp = min(maxTemp, h);
        minTemp = max(minTemp, l);

        lastT = t;

    }
    cout<<"YES\n";

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

/*
1
2 10
8 -8 7
16 -10 -5

1
3 -100
100 0 0
100 -50 50
200 100 100
*/
