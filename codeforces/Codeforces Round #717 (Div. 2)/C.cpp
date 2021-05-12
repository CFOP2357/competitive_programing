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

#define MAX 200010
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;
bool possible[150][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    ull sum = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        sum += z;
    }

    possible[0][a[0]]=true;
    for(int i=1; i<n; i++){
        possible[i][a[i]] = true;
        for(int j=0; j<MAX; j++){
            possible[i][j] = possible[i][j] || possible[i-1][j];
            if(possible[i-1][j])
                possible[i][j+a[i]]=true;
        }
    }

    if( !(sum%2) && possible[n-1][sum/2]){
        cout<<"1\n";
        for(ull i = 1; i<=2000; i*=2)
            for(int j=0; j<n; j++)
                if(a[j]&i){
                    cout<<j+1<<"\n";
                    return;
                }
    }
    else {
        cout<<"0\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
6
1 2 7 9 10 12
*/
