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

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 100100
#define MOD 1000000007


ull pos[MAX];
ull n;

void solve(){

    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        pos[z] = i;
    }

    ull actPos = n;
    vector<bool> selected(n+1, false);
    for(int i=1; i<=n; i++){
        //cout<<actPos<<" "<<pos[i]<<"\n";
        if(actPos == pos[i] || actPos == n || selected[actPos]){
            selected[pos[i]]=true;
            actPos = pos[i]+1;

        }
        else{
            cout<<"No\n";
            return;
        }
    }

    cout<<"Yes\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
3
1 3 2
*/
