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

vector<ull> a;
vector<ull> b;
ull n;
ull l, r, m;

void solve(){
    cin>>l>>r>>m;

    for(ull i = 0; i<=r-l; i++){
        ull k = m - i;
        if(k<l) continue;
        ull a = l;
        if(k%l)
            a += (k -(k%l));
        if(a <= r){
            //cout<<m<<" "<<k<<"#\n";
            ull n = (m - i)/a;
            if(n){
                cout<<a<<" "<<l+i<<" "<<l<<"\n";
                return;
            }
        }
    }

    for(ull i = 0; i<=r-l; i++){
        ull k = m + i;
        if(k<l) continue;
        ull a = l;
        if(i==1){
            cout<<k%l<<"\n";
        }
        if(k%l)
            a = (a+k%l)/;
        if(a <= r){
            //cout<<m<<" "<<k<<"#\n";
            ull n = (m + i)/a;
            if(n){
                cout<<a<<" "<<l<<" "<<l+i<<"\n";
                return;
            }
        }
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

