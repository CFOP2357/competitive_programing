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

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

vector<ull> a;
vector<ull> b;
ull n, m;

int A[1100], B[1100];

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    fill(A, A+1100, 0);
    fill(B, B+1100, 0);
    for(int i=0; i<n; i++){
        int z; cin>>z;
        A[z]++;
    }
    for(int i=0; i<m; i++){
        int z; cin>>z;
        B[z]++;
    }

    for(int i=0; i<1100; i++){
        if(A[i] && B[i]){
            cout<<"YES\n";
            cout<<1<<" "<<i<<"\n";
            return;
        }
    }

    cout<<"NO\n";
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

