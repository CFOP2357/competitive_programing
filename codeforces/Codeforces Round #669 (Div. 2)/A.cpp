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

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    for(int i=0; i<n; i+=2){
        if(a[i] && a[i+1]){
            if(b.size()%2 == 1){
                b.pop_back();
            }
            b.push_back(a[i]);
            b.push_back(a[i]);
        }
        else if(a[i] && !a[i+1]){
            b.push_back(0);
        }
        else if(!a[i] && a[i+1]){
            b.push_back(0);
        }
        else if(!a[i] && !a[i+1]){
            if(b.size()%2 == 1){
                b.pop_back();
            }
            b.push_back(a[i]);
            b.push_back(a[i]);
        }
    }

    cout<<b.size()<<"\n";
    for(int ans : b)
        cout<<ans<<" ";
    cout<<"\n";
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

