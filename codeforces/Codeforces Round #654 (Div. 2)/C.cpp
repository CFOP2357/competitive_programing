#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 1000100
#define MOD 1000000007

ull v, c;
ull n, m;

void solve(){
    cin>>v>>c;
    cin>>n>>m;

    if(v+c < n+m){
        cout<<"No\n";
        return;
    }

    if(v>c){
        if(c>=m){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    else {
        if(v>=m)
            cout<<"Yes\n";
        else cout<<"No\n";
    }


}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

