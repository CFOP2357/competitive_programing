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
ull n, k;

void solve(){
    a.clear(); b.clear();
    cin>>n>>k;

    bool exist = false;
    bool allK =true;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        exist = exist || z==k;
        allK = allK && z==k;
    }

    if(!exist){
        cout<<"no\n";
        return;
    }

    if(allK){
        cout<<"yes\n";
        return;
    }

    exist = false;

    for(int i=0; i<n; i++){
        if(a[i]>=k){

            if( (i>0 && a[i-1]>=k) || (i>1 && a[i-2]>=k) ){
                cout<<"yes\n";
                return;
            }

        }
    }

    cout<<"no\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

